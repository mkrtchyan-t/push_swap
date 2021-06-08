/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:37:37 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/26 15:38:30 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	index;

	if (!(str = ft_strdup(s)))
		return (NULL);
	index = 0;
	while (str[index])
	{
		str[index] = (*f)(index, str[index]);
		index++;
	}
	return (str);
}
