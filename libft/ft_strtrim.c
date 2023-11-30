/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:49:32 by jhouyet           #+#    #+#             */
/*   Updated: 2023/10/28 14:36:15 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && s1[j - 1] && ft_strchr(set, s1[j - 1]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (str != NULL)
		ft_strlcpy(str, &s1[i], (j - i + 1));
	return (str);
}
