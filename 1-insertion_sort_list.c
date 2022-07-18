/*
 * File: 1-insertion_sort_list.c
 * Auth: Tunde Okeowo & Temidayo Junaid-Eko
 */

#include "sort.h"


/**
 * swap_node - swap two nodes of a linkedlist
 *
 * @h: pointer to the base of linked list
 * @n1: pointer to the first node to be swapped
 * @n2: pointer tot the second node to be swpped
 *
 * Return: void
 */
void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts an unsorted double linkedlist
 * using the selection sort algorithm
 *
 * @list: pointer to the base of a double linkedlist
 * return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			swap_node(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
