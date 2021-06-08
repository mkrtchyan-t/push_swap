/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:43:55 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/30 14:44:33 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
