/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:00:56 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/21 14:01:32 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*space;

	len = ft_strlen(s1) + 1;
	space = (void *)malloc(len);
	if (!space)
		return (NULL);
	space = ft_memcpy(space, s1, len);
	return (space);
}
