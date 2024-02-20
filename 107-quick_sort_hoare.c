#include "sort.h"

/**
 * int_swaper4 - the positions of the two elements into an array
 * @array: arrray
 * @item1: array element
 * @item2: array element
 */
void int_swaper4(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_part - Hoare partition sorting scheme implementation
 * @array: array
 * @first: fisrt array element
 * @last: last array element
 * @size: size array
 * Return: return the position of the last element sorted
 */
int hoare_part(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[finder] > pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		int_swaper4(array, current, finder);
		print_array(array, size);
	}
}

/**
 * custom_quick - Quicksort algorithm implemantatiion
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
		position = hoare_part(array, first, last, size);
		custom_quick(array, first, position - 1, size);
		custom_quick(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - prepare the terrain for the quick sort algorithm
 * @array: array
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	custom_quick(array, 0, size - 1, size);
}
