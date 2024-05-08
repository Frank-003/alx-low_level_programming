#include "search_algos.h"

typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/**
 * jump_list - Searches for a value in a sorted list using Jump Search.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step, prev_idx, idx;
    listint_t *current;

    if (!list)
        return NULL;

    step = sqrt(size);
    current = list;
    prev_idx = 0;

    while (current->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev_idx, current->n);
        prev_idx = idx;
        for (idx = prev_idx; idx < prev_idx + step && current; idx++)
        {
            if (current->n == value)
                return current;
            current = current->next;
        }
    }

    printf("Value checked at index [%lu] = [%d]\n", prev_idx, current->n);
    if (current->n == value)
        return current;

    return NULL;
}

