/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:30:04 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/26 15:33:16 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_set(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	index;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && check_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_set(s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (start < end)
		result[index++] = s1[start++];
	result[index] = '\0';
	return (result);
}
