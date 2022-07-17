/*
 * File: 0-bubble_sort.c
 * Auth: Tunde Okeowo & Temidayo Junaid-Eko
 */

#include "sort.h"

/**
 * bubble_sort - perform bubble sort.
 *
 * @array: pointer to array of integers to be sorted
 * @size: size of the array
 *
 * return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swap = 1;
	size_t i, arr_len;

	if (array == NULL || size == 0)
		return;

	arr_len = size;
	while (swap)
	{
		swap = 0;
		for (i = 1; i <= arr_len - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_array(array, i);
				swap = 1;
				print_array(array, size);
			}
		}
		--arr_len;
	}
}
