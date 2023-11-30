/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:53:16 by jhouyet           #+#    #+#             */
/*   Updated: 2023/11/08 13:59:42 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(va_list arg)
{
	int	nb;
	int	count;

	nb = va_arg(arg, int);
	count = ft_count_nbr(nb);
	ft_putnbr_fd(nb, 1);
	return (count);
}
