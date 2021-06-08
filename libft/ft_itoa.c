/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:32 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/26 15:35:34 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long n)
{
	size_t	len;
	int		negative;

	len = 0;
	negative = 0;
	if (n < 0)
	{
		len++;
		negative++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*ft_gen(char *str, long nbr, int len, int negative)
{
	if (nbr != 0)
		str = malloc(sizeof(char) * (len + 1));
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		negative++;
		nbr = -nbr;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (negative == 1)
		str[0] = '-';
	else
		str[0] = (nbr % 10) + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;
	int		negative;

	nbr = n;
	len = ft_len(nbr);
	str = 0;
	negative = 0;
	if (!(str = ft_gen(str, nbr, len, negative)))
		return (0);
	return (str);
}
