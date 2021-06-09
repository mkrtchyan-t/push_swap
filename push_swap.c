/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:10:21 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/03 20:10:25 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_coordinate(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_sort_3(stacks);
	else if (stacks->count_a <= 5)
		ft_sort_5(stacks);
	else
		ft_global_sort(stacks);
}

int	main(int ac, char **av)
{
	t_data		*new;
	t_stacks	*stacks;

	if (ac < 2)
		exit(1);
	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	if (error_check(ac, av))
	{
		ft_separate(ac, av, new);
		ft_duplicate_check(new, stacks);
		if (ft_is_sorted(new))
		{
			ft_init_stack(new, stacks);
			ft_coordinate(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
