#include "sort.h"
/**
 *counting_sort - implements countin sort algorithm
 *@array: provided array
 *@size: size of provided array
 *
 */
void counting_sort(int *array, size_t size)
{
	int position, max_value = 0, *frequency_count = NULL, *temporary_array = NULL;
	size_t index;

	if (array == NULL || size < 2)
		return;
	index = 0;
	while (index < size)
	{
		if (array[index] > max_value)
			max_value = array[index];
		index++;
	}
	frequency_count = my_calloc(max_value + 1, sizeof(int));
	temporary_array = my_calloc(size + 1, sizeof(int));
	index = 0;
	while (index < size)
	{
		frequency_count[array[index]]++;
		index++;
	}
	position = 1;
	while (position <= max_value)
	{	frequency_count[position] += frequency_count[position - 1];
		position++;
	}
	print_array(frequency_count, max_value + 1);
	index = 0;
	while (index < size)
	{
		temporary_array[frequency_count[array[index]] - 1] = array[index];
		frequency_count[array[index]]--;
		index++;
	}
	index = 0;
	while (index < size)
	{	array[index] = temporary_array[index];
		index++;
	}
	free(temporary_array);
	free(frequency_count);
}

/**
 *my_calloc - behaves as a calloc function
 *@members: items provided
 *@size: size in mbs of each item
 *Return: pointer to given memeory
 *
 */
void *my_calloc(unsigned int members, unsigned int size)
{
	unsigned int index = 0;
	char *ptr;

	if (members == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(members * size);
	if (ptr == NULL)
	{

		return (NULL);
	}
	while (index < (members * size))
	{
		ptr[index] = '\0';
		index++;
	}
	return (ptr);
}
