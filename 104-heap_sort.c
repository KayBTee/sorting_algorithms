#include "sort.h"
#include <stdio.h>

/**
 * int_swaper2 - utility function to swap two integers
 * @a: integer a
 * @b: integer b
 */
void int_swaper2(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * Heapify_max - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (elemnt at index idx)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @index: index
 * @n: size of the array to run
 */
void Heapify_max(int *array, size_t size, int index, size_t n)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		int_swaper2(&array[index], &array[largest]);
		print_array(array, size);
		Heapify_max(array, size, largest, n);
	}
}

/**
 * heap_sort - The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		Heapify_max(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		int_swaper2(&array[0], &array[i]);
		print_array(array, size);

		Heapify_max(array, size, 0, i);
	}
}
