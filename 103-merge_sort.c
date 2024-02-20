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
	int left_idx = begin, right_idx = middle + 1, merge_idx = begin;
	int left_size = middle - begin + 1;
	int right_size = end - middle;

	int left_array[left_size], right_array[right_size];

	for (int i = 0; i < left_size; i++)
		left_array[i] = array[begin + i];
	for (int i = 0; i < right_size; i++)
		right_array[i] = array[middle + 1 + i];

	while (left_idx < left_size && right_idx < right_size)
	{
		if (left_array[left_idx - begin] <= right_array[right_idx - middle - 1])
			array[merge_idx++] = left_array[left_idx++ - begin];
		else
			array[merge_idx++] = right_array[right_idx++ - middle - 1];
	}

	while (left_idx < left_size)
		array[merge_idx++] = left_array[left_idx++ - begin];

	while (right_idx < right_size)
		array[merge_idx++] = right_array[right_idx++ - middle - 1];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left_size);
	printf("[right]: ");
	print_array(right_array, right_size);
	printf("[Done]: ");
	print_array(&array[begin], left_size + right_size);
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

	if (begin < end)
	{
		middle = (begin + end) / 2;

		merge_asc(array, temp, begin, middle);
		merge_asc(array, temp, middle + 1, end);

		make_merge(array, temp, begin, middle, end);
	}
}

