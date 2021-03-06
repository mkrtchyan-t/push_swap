/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordmalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:42:50 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/09 17:42:53 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordmalloc(char const *s, char **mass)
{
	int lenword;
	int i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			if (!(mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)))))
				return (i);
		}
		else
			s++;
	}
	return (0);
}
