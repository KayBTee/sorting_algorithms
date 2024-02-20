#include "sort.h"
#include <stdio.h>

/**
 * int_swaper3 - changed two valiues in ascending or descending order
 * @array: array
 * @item1: item one
 * @item2: item two
 * @ord: 1: ascending order, 0: descending order
 */
void int_swaper3(int array[], int item1, int item2, int ord)
{
	int temp;

	if (ord == (array[item1] > array[item2]))
	{
		temp = array[item1];
		array[item1] = array[item2];
		array[item2] = temp;
	}
}

/**
 * sort_merge - sort bitonic sequences recursively in both orders
 * @array: array
 * @first: first element
 * @size: elements  number
 * @asc: 1: ascending order, 0: descending order
 */
void sort_merge(int array[], int first, int size, int asc)
{
	int mid, i;

	if (size > 1)
	{
		mid = size / 2;
		for (i = first; i < first + mid; i++)
			int_swaper3(array, i, i + mid, asc);
		sort_merge(array, first, mid, asc);
		sort_merge(array, first + mid, mid, asc);
	}
}

/**
 * sort_bit - bitonic sort algorith implementation
 * @array: array
 * @first: first element
 * @items: number of elements
 * @size: array length
 */
void sort_bit(int array[], int first, int items, int size)
{
	int mid;

	if (items > 1)
	{
		if (size >= 1)
		{
			printf("Merging [%i/%i] (UP);\n", items, size);
			print_array(&array[first], items);
		}
		mid = items / 2;
		sort_bit(array, first, mid, 1);
		sort_bit(array, first + mid, mid, 0);
		sort_merge(array, first, items, size);
		if (size <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", items, size);
			print_array(&array[first], items);
		}
		if (size >= 1)
		{
			printf("Result [%i/%i] (UP):\n", items, size);
			print_array(&array[first], items);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array length
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	sort_bit(array, 0, size, order);
}
