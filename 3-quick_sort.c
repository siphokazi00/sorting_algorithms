#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursive function for Quick Sort
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: The total size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, partition - 1, size);
		quicksort_recursive(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: The total size of the array
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}
