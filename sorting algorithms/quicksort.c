#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void qksort(int *number, int first, int last)
{
	int i, j, pivot;

	if (first < last)
	{
		pivot = (first + last) / 2;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				swap(&number[i], &number[j]);
		}
		swap(&number[j], &number[pivot]);
		qksort(number, first, j - 1);
		qksort(number,j + 1,last);
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