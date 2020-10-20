#include "sort.h"

/**
 * quick_sort - sorts an array using the quicksort algorithm, and Lomuto scheme
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recur_call(array, 0, size - 1, size);
}

/**
 * recur_call - function in charge of making the recursive call
 *
 * @array: array to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the original array
 *
 * Return: void
 */
void recur_call(int *array, int lo, int hi, size_t size)
{
	int p_index;

	if (lo < hi)
	{
		p_index = partition(array, lo, hi, size);
		recur_call(array, lo, p_index - 1, size);
		recur_call(array, p_index + 1, hi, size);
	}
}

/**
 * partition - puts all the elements lower than the last element
 * of the list before it, and the higher after it
 *
 * @array: awway to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the original array
 *
 * Return: void
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo, loop, tmp;

	for (loop = i; loop < hi; loop++)
	{
		if (array[loop] < pivot)
		{
			/*Swaps array[i] with array[loop]*/
			if (array[i] != array[loop])
			{
				tmp = array[i];
				array[i] = array[loop];
				array[loop] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[hi])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i);
}
