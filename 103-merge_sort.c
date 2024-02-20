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
	merge_asc(array, temp, 0, size / 2, size - 1);
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
 *merge_asc - sorts an array of integers in
 *ascending order using merge sort algorithm
 *@array: An array of integers to be sorted
 *@temp: used in merge
 *@begin:position of first element
 *@middle:position of middle element
 *@end: position of last element
 *
 */
void merge_asc(int *array, int *temp, int begin, int middle, int end)
{
	if (begin < end)
	{
		int middle = (begin + end) / 2;

		merge_asc(array, temp, begin, middle);
		merge_asc(array, temp, middle + 1, end);
		make_merge(array, temp, begin, middle, end);
	}
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
	int left_idx = begin, right_idx = middle + 1, temp_idx = begin;

	while (left_idx <= middle && right_idx <= end)
	{
		if (array[left_idx] <= array[right_idx])
			temp[temp_idx++] = array[left_idx++];
		else
			temp[temp_idx++] = array[right_idx++];
	}
	while (left_idx <= middle)
		temp[temp_idx++] = array[left_idx++];

	while (right_idx <= end)
		temp[temp_idx++] = array[right_idx++];

	for (int i = begin; i <= end; i++)
		array[i] = temp[i];
}
