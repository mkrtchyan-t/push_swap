/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:13:10 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/03 20:13:16 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int *array, int low, int high)
{
	int	pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;
	j = low;
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

void	ft_quicksort(int *array, int first, int last)
{
	int pi;

	if (first < last)
	{
		pi = partition(array, first, last);
		ft_quicksort(array, first, pi - 1);
		ft_quicksort(array, pi + 1, last);
	}
}
