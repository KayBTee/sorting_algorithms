#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * max_value - A utility function to get maximum value in arr[]
 * @arr: array
 * @n: size of the array
 * Return: array
 */
int max_value(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * sort_count - A function to do counting sort of arr[] according to
 * the digit represented by exp.
 * @array: array
 * @n: size of the array
 * @expo: exp is 10^i
 * @output: array to save the temporary values
 */
void sort_count(int *array, size_t n, int expo, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n ; i++)
		count[(array[i] / expo) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / expo) % 10] - 1] = array[1];
		count[(array[i] / expo) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		array[i] = output[i];
	/*print_array(array, n);*/
}
/**
 * radix_sort - The main function that sorts arr[]
 * of size n using Radix sort
 * @array: array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, maximum = 0;
	int *output = NULL;

	if (array == NULL || size < 2)
		return;
	maximum = max_value(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		sort_count(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
