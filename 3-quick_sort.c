/*
 * File: 3-quick_sort.c
 * Auth: Tunde Okeowo & Temidayo Junaid-Eko
 */

#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * lomuto_partition - partition array based on Lomuto's
 * partiotining algorithm
 *
 * @array: pointer to array of integers
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 *
 * Return: partition index
 */
int lomuto_partition(int *array, int start, int end, size_t size)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * quick_sort - function sort array of integers in ascending
 * order using quicksort
 *
 * @array: pointer to array of integers
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_sort(array, 0, size - 1, size);
}

/**
 * _sort - function sort arrray of integers using quick_sort
 *
 * @array: pointer to the array of integers
 * @start: the start of the array
 * @end: the end of the array
 * @size: is the size of the array
 *
 * Return: void
 */
void _sort(int *array, int start, int end, size_t size)
{
	int p;

	if (start < end)
	{
		p = lomuto_partition(array, start, end, size);
		_sort(array, start, p - 1, size);
		_sort(array, p + 1, end, size);
	}
}
