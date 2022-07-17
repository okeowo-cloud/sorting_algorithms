/*
 * File: 2-selection_sort.c
 * Auth: Tunde Okeowo & Temidayo Junaid-Eko
 */

#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: pointer to an array of integers
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int jmin, tmp;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		jmin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[(int)jmin])
				jmin = (int)j;
		}
		if (jmin != (int)i)
		{
			tmp = array[(int)i];
			array[(int)i] = array[jmin];
			array[jmin] = tmp;
			print_array(array, size);
		}
	}
}
