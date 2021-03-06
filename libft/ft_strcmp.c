/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:50:37 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/21 13:51:19 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2 || *s2 > *s1)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if ((*s1 == '\0' && *s2 == '\0'))
		return (0);
	return (*s1 - *s2);
}