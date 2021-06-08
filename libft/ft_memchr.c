/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:34:33 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/21 13:40:45 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	tmp;
	size_t	index;

	tmp = c;
	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == tmp)
			return (((unsigned char *)s) + index);
		index++;
	}
	return (NULL);
}
