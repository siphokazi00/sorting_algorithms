#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		sorted = current->prev;
		while (sorted != NULL && current->n < sorted->n)
		{
			temp = sorted->prev;

			if (temp != NULL)
				temp->next = current;
			else
				*list = current;

			if (sorted->next != NULL)
				sorted->next->prev = sorted->prev;

			sorted->next = current->next;
			sorted->prev = current;
			current->next = sorted;

			print_list(*list);
			sorted = temp;
		}
		current = current->next;
	}
}
