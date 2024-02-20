#include "sort.h"

/**
 * change_swap - swaps the positions of two elements in an array
 * @array: array
 * @item1: index of the first element
 * @item2: index of the second element
 */
void change_swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp = array[item1];

	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * re_partition - custom partition sorting scheme implementation
 * @array: array
 * @first: index of the first element
 * @last: index of the last element
 * @size: size of the array
 * Return: returns the position of the last element sorted
 */
int re_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				change_swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		change_swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * quick_sort- prepare the terrain for a custom quicksort algorithm
 * @array: array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	custom_quick(array, 0, size - 1, size);
}

/**
 * custom_quick - quicksort algorith implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 */
void custom_quick(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = re_partition(array, first, last, size);

		custom_quick(array, first, position - 1, size);
		custom_quick(array, position + 1, last, size);
	}
}
