#include "sort.h"
/**
 *shell_sort - sorts an array of integers from small to big
 *using shell sort algorithm and Knuth sequence
 *@size: Array size
 *@array: list of the integers
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, currentPos = 0, indx;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (; gap < size / 3; gap = 3 * gap + 1)
		;

	for (; gap >= 1; gap /= 3)
	{

		for (indx = gap; indx < size; indx++)
		{

			for (currentPos = indx; currentPos >= gap &&
					(array[currentPos] < array[currentPos - gap]); currentPos -= gap)
			{

				int_swaper(array, currentPos, currentPos - gap);

			}

		}
		print_array(array, size);
	}


}

/**
 *int_swaper - exchanges number positions in array
 *@array:pointerto the array of numbers
 *@intOne: number in the array
 *@intTwo: number in the array
 */
void int_swaper(int *array, int intOne, int intTwo)
{

	int temp;

	temp = array[intOne];
	array[intOne] = array[intTwo];
	array[intTwo] = temp;

}
