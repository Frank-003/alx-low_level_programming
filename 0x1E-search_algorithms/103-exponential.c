#include "search_algos.h"

/**
  * _binary_search - Searches for a value in a sorted array
  *                  of integers using binary search.
  * @array: A pointer to the first element of the array to search.
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int binary_search(int *array, int low, int high, int value) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/**
  * exponential_search - Searches for a value in a sorted array
  *                      of integers using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  */
int exponential_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0)
        return -1;

    if (array[0] == value) {
        printf("Comparing value %d with array[%d] = %d\n", value, 0, array[0]);
        return 0;
    }

    int i = 1;
    while (i < size && array[i] <= value) {
        printf("Comparing value %d with array[%d] = %d\n", value, i, array[i]);
        i *= 2;
    }

    int low = i / 2;
    int high = (i < size) ? i : size - 1;

    printf("Exponential search range: [%d, %d]\n", low, high);

    return binary_search(array, low, high, value);
}

