#include "sort.h"
/**
 *bubble_sort - sorts the array elements from
 *smallest  to largest
 *
 *@array: array of elements
 *@size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{

	size_t index1 = 0;
	size_t index2, temp = 0;

	if (size < 2)
	{
		return;
	}
	while (index1 < size)
	{

		for (index2 = 0; index2 < size - 1; index2++)
		{

			if (array[index2] > array[index2 + 1])
			{

				temp = array[index2];
				array[index2] = array[index2 + 1];
				array[index2 + 1] = temp;
				print_array(array, size);
			}

		}
		index1++;
	}

}
