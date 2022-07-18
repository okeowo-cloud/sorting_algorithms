#include "sort.h"
/**
 * counting_sort - function sorts an array of integers in asce
 * nding order.
 * @array: array to be sorted
 * @size: size of array
 * Return: always 0
 */
void counting_sort(int *array, size_t size)
{
	int maxElem = array[0];
	int *k_array, *array1, i;

	if (!array || size < 2)
		return;
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > maxElem)
			maxElem = array[i];
	}
	k_array = malloc(sizeof(int) * (maxElem + 1));
	if (k_array == NULL)
		return;
	array1 = malloc(sizeof(int) * size);
	if (!array1)
	{
		free(k_array);
		return;
	}
	for (i = 0; i < (maxElem + 1); i++)
		k_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		k_array[array[i]] += 1;

	for (i = 0; i < (maxElem + 1); i++)
		k_array[i] += k_array[i - 1];

	print_array(k_array, (size_t)maxElem + 1);

	for (i = 0; i < (int)size; i++)
	{
		array1[k_array[array[i]] - 1] = array[i];
		k_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = array1[i];

	free(k_array);
	free(array1);
}
