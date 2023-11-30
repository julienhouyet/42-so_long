/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:53:28 by jhouyet           #+#    #+#             */
/*   Updated: 2023/11/08 12:42:05 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_number(va_list arg)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(arg, unsigned int);
	count = ft_count_nbr_unsigned(nb);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, 1);
		ft_putnbr_fd(nb % 10, 1);
	}
	else
		ft_putchar_fd(nb + '0', 1);
	return (count);
}
