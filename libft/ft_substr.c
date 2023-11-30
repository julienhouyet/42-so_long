/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:15:59 by jhouyet           #+#    #+#             */
/*   Updated: 2023/11/03 11:28:59 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		new_str = ft_calloc(1, sizeof(char));
		if (!new_str)
			return (NULL);
	}
	else
	{
		new_len = ft_strlen(s + start);
		if (!(new_len < len))
			new_len = len;
		new_str = (char *)malloc((new_len + 1) * sizeof(char));
		if (!new_str)
			return (NULL);
		new_str[new_len] = 0;
		while (new_len-- > 0)
			new_str[new_len] = s[start + new_len];
	}
	return (new_str);
}
