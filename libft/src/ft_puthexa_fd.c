/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:53:25 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/20 10:28:40 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_puthexa_fd(unsigned long nb, char var, int fd)
{
	if (nb >= 16)
	{
		ft_puthexa_fd(nb / 16, var, fd);
		ft_puthexa_fd(nb % 16, var, fd);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar_fd(nb + '0', fd);
		}
		else
		{
			if (var == 'x')
				ft_putchar_fd(nb % 10 + 'a', fd);
			if (var == 'X')
				ft_putchar_fd(nb % 10 + 'A', fd);
		}
	}
}
