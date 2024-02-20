#include "sort.h"
/**
 *merge_sort - uses merge sort algorithm to
 *sort an array in ascending order
 *@size: list size
 *@array: an array of integers
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = my_calloc(size, sizeof(int));
	merge_asc(array, temp, 0, size - 1);
	free(temp);
}

/**
 *my_calloc - represents a calloc function
 *@members: represents number of element
 *@size: size ofeach of the given elements
 *Return: pointer to where memory is assigned
 */
void *my_calloc(unsigned int members, unsigned int size)
{

	char *ptr;
	unsigned int index;


	if (members == 0 || size == 0)
		return (NULL);
	ptr = malloc(members * size);

	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (index < (members * size))
	{
		ptr[index] = '\0';
		index++;
	}

	return (ptr);
}

/**
 *make_merge - makes a merge
 *@array: original array to be sorted
 *@temp: is a temporary array
 *used for merging and storing
 *intermediate results
 *@begin:position of first element
 *@middle: position of middle element
 *@end: position of last element
 */
void make_merge(int *array, int *temp, int begin, int middle, int end)
{
	int left_size = middle - begin + 1;
	int right_size = end - middle, left_idx, right_idx, merge_idx = begin;
	int *left_array, *right_array;

	right_array = &temp[right_size];
	left_array = &temp[0];

	for (left_idx = 0; left_idx < left_size; left_idx++)
		left_array[left_idx] = array[begin +  left_idx];
	for (right_idx = 0; right_idx < right_size; right_idx++)
		right_array[right_idx] = array[middle + 1 + right_idx];
	left_idx = 0;
	right_idx = 0;

	while (left_idx < left_size && right_idx < right_size)
	{
		if (left_array[left_idx] <= right_array[right_idx])
			array[merge_idx] = left_array[left_idx++];
		else
			array[merge_idx] = right_array[right_idx++];
		merge_idx++;
	}

	for (; left_idx < left_size; left_idx++, merge_idx++)
		array[merge_idx] = left_array[left_idx];

	for (; right_idx < right_size; right_idx++, merge_idx++)
		array[merge_idx] = right_array[right_idx];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left_idx);
	printf("[right]: ");
	print_array(right_array, right_idx);
	printf("[Done]: ");
	print_array(&array[begin], left_idx + right_idx);
}
/**
 *merge_asc - sorts an array of integers in
 *ascending order using merge sort algorithm
 *@array: An array of integers to be sorted
 *@temp: used in merge
 *@begin:position of first element
 *@end: position of last element
 *
 */
void merge_asc(int *array, int *temp, int begin, int end)
{
	int middle;

	middle = (begin + end) / 2;
	if ((begin + end) % 2 == 0)
	{

		middle--;
	}
	if (middle >= begin)
	{
		merge_asc(array, temp, begin, middle);
		merge_asc(array, temp, middle + 1, end);
		merge_asc(array, temp, begin, end);
	}
}
