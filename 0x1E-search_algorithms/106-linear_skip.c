#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list using linear skip search.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *express;

    if (!list)
        return NULL;

    current = list;
    express = list->express;

    while (express)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->n, express->n);
        if (express->n >= value)
            break;
        current = express;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", current->n, express->n);

    while (current)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->n, current->n);
        if (current->n == value)
            return current;
        current = current->next;
    }

    return NULL;
}


