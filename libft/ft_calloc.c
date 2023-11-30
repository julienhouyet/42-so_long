/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:52:49 by jhouyet           #+#    #+#             */
/*   Updated: 2023/10/30 08:26:56 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	size_t	s;

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
