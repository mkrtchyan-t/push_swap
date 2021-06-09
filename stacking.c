/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:13:27 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/03 20:13:51 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_int_overflow(char *str)
{
	if (ft_strlen(str) != ft_nbrlen(ft_atoi(str)))
		ft_error();
	if ((str[0] != '-' && (ft_atoi(str)) < 0)
		|| (str[0] == '-' && (ft_atoi(str)) > 0))
		ft_error();
}

void	ft_stacking(t_data *new, int *buff, int count)
{
	int	i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}

void	ft_separate(int ac, char **av, t_data *new)
{
	int		p;
	int		i;
	int		*buff;
	int		count;
	char	**mass;

	i = 1;
	while (i < ac)
	{
		p = -1;
		count = ft_countword(av[i]);
		mass = ft_strsplit(av[i], count);
		buff = (int *)malloc(sizeof(int) * (count));
		if (!buff)
			exit(1);
		while (count > ++p)
		{
			ft_check_int_overflow(mass[p]);
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		ft_stacking(new, buff, count);
		i++;
	}
}
