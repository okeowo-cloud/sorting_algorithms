#include "sort.h"

/**
 * topDownMerge - function merge splits
 * @array: array with items to merge
 * @array_copy: working array to store the sorted array
 * @mid: middle of array
 * @front: start inde  of array
 * @back: end index of array
 */
void topDownMerge(int *array, int *array_copy, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + front, mid - front);

	printf("[right]: ");
	print_array(array + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		array_copy[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		array_copy[k++] = array[i];
	for (; j < back; j++)
		array_copy[k++] = array[j];
	for (i = front, k = 0; i < back; i++)
		array[i] = array_copy[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
 * topDownSplitMerge - split array from top to bottom then merge
 *
 * @array: array of integers to sort
 * @array_copy: to store the sorted result
 * @front: the front index of array
 * @back: the end index of array
 */
void topDownSplitMerge(int *array, int *array_copy, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		topDownSplitMerge(array, array_copy, front, mid);
		topDownSplitMerge(array, array_copy, mid, back);
		topDownMerge(array, array_copy, front, mid, back);
	}
}

/**
 * merge_sort - function sorts an arrays of integers in
 * ascending order using the merge sort algorithm
 *
 * @array: pointer to an array of integers
 * @size: is the size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy;

	if (array == NULL || size < 2)
		return;

	array_copy = malloc(sizeof(int) * size);
	if (!array_copy)
		return;

	topDownSplitMerge(array, array_copy, 0, size);

	free(array_copy);
}
