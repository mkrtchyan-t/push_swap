/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:08:31 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/03 20:08:33 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stacks *s, int i)
{
	rra(&s->a, i);
	rrb(&s->b, i);
	if (i == 1)
		write(1, "rrr\n", 4);
}

int	ft_is_sorted(t_data *new)
{
	int	i;

	i = 0;
	while (i < (new->count_element - 1))
	{
		if (new->a[i] > new->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_only_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
