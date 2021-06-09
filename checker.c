/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:43:50 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/08 21:15:07 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instructions(t_stacks *s, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		sa(s->a, 0);
	else if (ft_strcmp(str, "sb") == 0)
		sb(s->b, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ss(s, 0);
	else if (ft_strcmp(str, "ra") == 0)
		ra(&s->a, 0);
	else if (ft_strcmp(str, "rb") == 0)
		rb(&s->b, 0);
	else if (ft_strcmp(str, "rr") == 0)
		rr(s, 0);
	else if (ft_strcmp(str, "rra") == 0)
		rra(&s->a, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(&s->b, 0);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(s, 0);
	else if (ft_strcmp(str, "pa") == 0)
		pa(s, 0);
	else if (ft_strcmp(str, "pb") == 0)
		pb(s, 0);
	else
		ft_error();
}

void	ft_read_line(t_stacks *s)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_instructions(s, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	ft_stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_stack	*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	ft_null(stacks, new);
	if (error_check(argc, argv))
	{
		ft_separate(argc, argv, new);
		ft_duplicate_check(new, stacks);
		ft_init_stack(new, stacks);
		ft_read_line(stacks);
		if ((ft_stack_sorted(stacks)) && stacks->count_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}
