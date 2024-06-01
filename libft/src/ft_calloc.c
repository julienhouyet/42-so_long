/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:52:49 by jhouyet           #+#    #+#             */
/*   Updated: 2024/06/01 12:42:48 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	size_t	s;
	size_t	verif;

	verif = count * size;
	if (size != verif / count)
		return (0);
	s = (count * size);
	b = malloc(count * size);
	if (b != NULL)
	{
		ft_bzero(b, s);
		return (b);
	}
	else
		return (0);
}
