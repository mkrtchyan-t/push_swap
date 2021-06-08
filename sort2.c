/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:48:15 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/07 20:10:54 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_smaller(t_stack *a, int buff, int src)
{
	t_stack	*tmp;
	int		ret;

	tmp = a;
	ret = 0;
	while (tmp && ret == 0)
	{
		if (tmp->data < buff && tmp->data > src)
			ret = 1;
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_find_place_helper(t_stacks *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->data;
		if (b->data > s->a->data)
		{
			*action += 1;
			if (b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller(s->a, *buff, b->data) == 1)
	{
		while (s->a)
		{
			if (s->a->data < *buff && s->a->data > b->data)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int		ft_find_place(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int	action;
	int	ret;
	int	buff;

	action = 0;
	buff = 0;
	ft_find_place_helper(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		ret = action + b->step;
	}
	else
		ret = min;
	return (ret);
}

int		ft_min_count(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
