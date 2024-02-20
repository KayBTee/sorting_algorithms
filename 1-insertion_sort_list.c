#include "sort.h"
/**
 *insertion_sort_list - sorts a doubly linked list
 *of integers from smallest to largest using the insertion algorithm
 *@list: Double linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *new_node;

	if (list == NULL || (*list)->next == NULL)
	{

		return;
	}
	new_node = (*list)->next;

	for (; new_node;)
	{

		while (new_node->prev && new_node->prev->n > new_node->n)
		{

			new_node = my_node_swap(new_node, list);
			print_list(*list);
		}

		new_node = new_node->next;
	}
}
/**
 *my_node_swap - swaps a new node for the previous one
 *
 *@node: the node
 *@list: a list of nodes
 *Return: return pointer of current node
 *
 */
listint_t *my_node_swap(listint_t *node, listint_t **list)
{

	listint_t *old_node = node->prev;
	listint_t *current_node = node;

	old_node->next = current_node->next;
	if (current_node->next)
	{

		current_node->next->prev = old_node;
	}
	current_node->next = old_node;
	current_node->prev = old_node->prev;
	old_node->prev = current_node;
	if (current_node->prev)
	{

		current_node->prev->next = current_node;
	}
	else
	{

		*list = current_node;
	}
	return (current_node);
}
