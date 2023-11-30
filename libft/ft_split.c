/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:54:56 by jhouyet           #+#    #+#             */
/*   Updated: 2023/10/30 13:30:36 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (words);
		}
		i++;
	}
	return (words);
}

static void	ft_free(char **tabs, size_t i)
{
	while (i > 0)
	{
		free(tabs[i]);
		i--;
	}
	free(tabs[0]);
	free(tabs);
}

static int	ft_split_words(char **tabs, char const *s, char c, int word)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == 0))
		{
			tabs[word] = malloc(sizeof(char) * (end - start + 2));
			if (!tabs[word])
			{
				ft_free(tabs, word);
				return (0);
			}
			ft_strlcpy(tabs[word], (s + start), end - start + 2);
			word++;
		}
		end++;
	}
	tabs[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tabs;

	if (!s)
		return (NULL);
	tabs = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tabs)
		return (NULL);
	if (!ft_split_words(tabs, s, c, 0))
		return (NULL);
	return (tabs);
}
