/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:19:43 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/07 19:47:38 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ra(&stacks->a, 1);
		else
			rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			rb(&stacks->b, 1);
		else
			rrb(&stacks->b, 1);
		steps->count_b--;
	}
	pa(stacks, 1);
}

void	ft_min_step(t_stacks *stacks, t_steps *steps)
{
	int		min;
	t_stack	*a1;
	t_stack	*b1;

	min = -1;
	a1 = stacks->a;
	b1 = stacks->b;
	while (stacks->b)
	{
		min = ft_find_place(stacks, stacks->b, steps, min);
		stacks->a = a1;
		stacks->b = stacks->b->next;
	}
	stacks->b = b1;
}

void	ft_step(t_stack *b, int count)
{
	int		i;
	int		half;
	t_stack	*buff;

	i = -1;
	half = count / 2;
	buff = b;
	while (++i <= half)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

void	ft_start_sort(t_stacks *stacks)
{
	t_steps	*step;

	if (!(step = (t_steps *)malloc(sizeof(t_steps))))
		exit(1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_step(stacks->a, stacks->count_a);
		ft_step(stacks->b, stacks->count_b);
		ft_min_step(stacks, step);
		ft_exec(stacks, step);
	}
	if ((ft_min_count(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->data != stacks->min)
			rra(&stacks->a, 1);
	}
	else
	{
		while (stacks->a->data != stacks->min)
			ra(&stacks->a, 1);
	}
	free(step);
}

void	ft_global_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			pb(stacks, 1);
			if (stacks->b->data > stacks->med)
				rb(&stacks->b, 1);
		}
		else
			ra(&stacks->a, 1);
	}
	if (stacks->a->data < stacks->a->next->data)
		sa(stacks->a, 1);
	pa(stacks, 1);
	ft_start_sort(stacks);
}
