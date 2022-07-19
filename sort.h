#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_array(int *a, size_t k);
void _sort(int *array, int start, int end, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
<<<<<<< HEAD
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **slow, listint_t **fast, listint_t **list);
=======
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
>>>>>>> 6d034c24c8bef65f72334d20622873b3bab5b8dc

#endif /* __SORT_H__ */
