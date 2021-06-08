/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:38:52 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/26 15:39:43 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	chr;

	if ((unsigned char)c >= 0x80)
	{
		chr = (unsigned char)c / 0x40 + 0xC0;
		write(fd, &chr, 1);
		chr = (unsigned char)c % 0x40 + 0x80;
		write(fd, &chr, 1);
	}
	else
		write(fd, &c, 1);
}
