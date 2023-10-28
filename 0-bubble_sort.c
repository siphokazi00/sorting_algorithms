#include "sort.h"

/**
 * swap - swaps two ints
 * @a: pointer to the first int
 * @b: pointer to the second int
 * Return: 0
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an int arr in ascending order using bubble sort
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
