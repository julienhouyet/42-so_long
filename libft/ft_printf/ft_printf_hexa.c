/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:53:12 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/15 09:33:52 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(char var, va_list *arg)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(*arg, unsigned int);
	count = ft_count_hexa(nb);
	ft_puthexa_fd(nb, var, 1);
	return (count);
}
