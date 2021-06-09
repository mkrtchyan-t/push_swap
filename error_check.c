/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:59:04 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/03 19:59:29 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(int argc, char **argv)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_check_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

void	ft_check_str(char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			nbr++;
		else if (ft_isspace(str[i]))
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-')
				&& (sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

void	ft_search_duplicate(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}

void	ft_duplicate_check(t_data *new, t_stacks *stacks)
{
	int			*dup;

	dup = (int *)malloc(sizeof(int) * (new->count_element));
	if (!dup)
		ft_error();
	dup = ft_intcpy(dup, new->a, new->count_element);
	ft_quicksort(dup, 0, new->count_element - 1);
	ft_search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}
