/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:53:26 by jhouyet           #+#    #+#             */
/*   Updated: 2023/11/08 13:57:48 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(va_list arg)
{
	unsigned long	nb;
	int				count;

	nb = va_arg(arg, unsigned long);
	count = ft_count_hexa(nb);
	ft_putstr_fd("0x", 1);
	ft_puthexa_fd(nb, 'x', 1);
	return (count + 2);
}
