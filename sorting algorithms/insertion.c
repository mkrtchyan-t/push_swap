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

void issort (int *array, int size)
{
	int current;
	int i;
	int j;

	j = 1;
	while(j < size)
	{
		i = j - 1;
		while (i >= 0 && array[i] > array[i + 1])
		{
			swap(&array[i], &array[i + 1]);
			i--;
		}
		j++;
	}
}

int	main(void)
{
	int size;
	int i = 0;
	int array[] = {2, 0, 1, 6, 8, 4, 6, 92, 1, 1234};
	size = sizeof(array) / sizeof(int);
	issort(array, size);
	while (i < size)
		printf("%d ", array[i++]);
	printf("\n");
	return (0);
}