#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	while (j <= high)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void qksort(int *array, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		qksort(array, low, pi - 1);
		qksort(array, pi + 1, high);
	}
}

int	main(void)
{
	int size;
	int i = 0;
	int array[] = {291, 939, -157, 671, -268};

	size = sizeof(array) / sizeof(int);
	printf("size: %d\n", size);
	qksort(array, 0, size - 1);
	while (i < size)
		printf("%d ", array[i++]);
	printf("\n");
	return (0);
}