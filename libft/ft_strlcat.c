/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:04 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/21 14:03:53 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	dstlen;
	size_t	left;

	dest = dst;
	source = (char *)src;
	left = dstsize;
	while (left-- != 0 && *dest != '\0')
		dest++;
	dstlen = dest - dst;
	left = dstsize - dstlen;
	if (left == 0)
		return (dstlen + ft_strlen(source));
	while (*source != '\0')
	{
		if (left > 1)
		{
			*dest++ = *source;
			left--;
		}
		source++;
	}
	*dest = '\0';
	return (dstlen + (source - src));
}
