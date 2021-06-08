/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:29:34 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/21 13:41:59 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			index;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	index = 0;
	while (index < n)
	{
		dest[index] = source[index];
		if ((unsigned char)c == source[index] ||
			(unsigned char)c == dest[index])
		{
			return (dst + index + 1);
		}
		index++;
	}
	return (NULL);
}
