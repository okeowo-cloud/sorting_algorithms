#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * swap_array - function swap two integers of an array
 *
 * @a: pointer to an int array.
 * @k: index to swap.
 *
 * return: void
 */
void swap_array(int *a, size_t k)
{
	int tmp;

	tmp = a[k];
	a[k] = a[k - 1];
	a[k - 1] = tmp;
}
