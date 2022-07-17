/*
 * File: 1-insertion_sort_list.c
 * Auth: Tunde Okeowo & Temidayo Junaid-Eko
 */

#include "sort.h"


/**
 * swap_node - swap two nodes of a linkedlist
 * @n: pointer to the first node to be swapped
 * @m: pointer to the seconde node to be swapped
 *
 * Return: void
 */
void swap_node(listint_t *n, listint_t *m)
{
	if (n->prev)
		n->prev->next = m;
	if (m->next)
		m->next->prev = n;
	n->next = m->next;
	m->prev = n->prev;
	n->prev = m;
	m->next = n;
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
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_node(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
		i = i->next;
	}
}
