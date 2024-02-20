#include "sort.h"
/**
 *cocktail_sort_list - function implementing the cocktail sort
 *@list: The list
 */
void cocktail_sort_list(listint_t **list)
{

	listint_t *current_node;
	int swap_occured = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current_node = *list;
	for (; swap_occured == 1;)
	{
		swap_occured = 0;
		for (; current_node->next;)
		{
			if (current_node->n > current_node->next->n)
			{
				current_node = change_node_position(current_node->next, list);
				swap_occured = 1;
				print_list(*list);
			}
			current_node = current_node->next;
		}
		if (swap_occured == 0)
		{
			break;
		}
		swap_occured = 0;
		for (; current_node->prev;)
		{
			if (current_node->n < current_node->prev->n)
			{

				current_node = change_node_position(current_node, list);
				swap_occured = 1;
				print_list(*list);
			}
			else
			{
				current_node = current_node->prev;
			}
		}
	}
}

/**
 *change_node_position - changes node
 *position and replaces it with previous node
 *@node: represents the node
 *@list: represnts node list
 *Return: pointer to provided node
 */
listint_t *change_node_position(listint_t *node, listint_t **list)
{

	listint_t *previous_node = node->prev, *current_node = node;

	previous_node->next = current_node->next;
	if (current_node->next)
	{
		current_node->next->prev = previous_node;
	}
	current_node->next = previous_node;
	current_node->prev = previous_node->prev;
	previous_node->prev = current_node;
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
