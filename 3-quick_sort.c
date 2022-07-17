/*
 * File: 3-quick_sort.c
 * Auth: Tunde Okeowo & Temidayo Junaid-Eko
 */

#include "sort.h"

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
	int p, i, p_index, tmp;

	p = array[end];
	p_index = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= p)
		{
			tmp = array[i];
			array[i] = array[p_index];
			array[p_index] = tmp;
			if (i != p_index)
				print_array(array, size);
			p_index++;
		}
	}
	if (end != p_index)
	{
		tmp = array[end];
		array[end] = array[p_index];
		array[p_index] = tmp;
		print_array(array, size);
	}

	return (p_index);
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
	int start, end;

	start = 0;
	end = (int) size - 1;
	_sort(array, start, end, size);
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
