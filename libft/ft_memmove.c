/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:32:26 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/22 15:22:03 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t index;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	if (src < dst)
	{
		index = len;
		while (index > 0)
		{
			index--;
			((char *)dst)[index] = ((char *)src)[index];
		}
	}
	else
	{
		index = 0;
		while (index < len)
		{
			((char *)dst)[index] = ((char *)src)[index];
			index++;
		}
	}
	return (dst);
}
