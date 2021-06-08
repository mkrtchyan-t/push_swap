/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:40:26 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/30 14:41:44 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	if (!(item = (t_list *)malloc(sizeof(*item))))
		return (NULL);
	item->content = content;
	item->next = NULL;
	return (item);
}
