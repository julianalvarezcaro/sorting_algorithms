#include "sort.h"

/**
 * bubble_sort - sorting function using bubble sort algorithm
 *
 * @array: array of ints to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t loop;
	int tmp, change, order = 0;

	while (!order)
	{
		change = 0;
		for (loop = 1; loop < size; loop++)
		{
			if (array[loop - 1] > array[loop])
			{
				tmp = array[loop - 1];
				array[loop - 1] = array[loop];
				array[loop] = tmp;
				print_array(array, size);
				change = 1;
			}
		}
		if (!change)
			order = 1;
	}
}
