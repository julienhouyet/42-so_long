/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:53:12 by jhouyet           #+#    #+#             */
/*   Updated: 2023/11/08 13:57:56 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(char var, va_list arg)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(arg, unsigned int);
	count = ft_count_hexa(nb);
	ft_puthexa_fd(nb, var, 1);
	return (count);
}
