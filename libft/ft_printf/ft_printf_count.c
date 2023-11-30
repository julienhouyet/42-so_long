/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:27:24 by jhouyet           #+#    #+#             */
/*   Updated: 2023/11/08 12:41:58 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_count_nbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_count_hexa(unsigned long nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}
