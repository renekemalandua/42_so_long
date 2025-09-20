/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 05:13:27 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/04 08:30:42 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stddef.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_count_char_start(char const *s, char c, int start)
{
	int	end;

	end = 0;
	while (s[start + end] != c && s[start + end] != '\0')
		end++;
	return (end);
}

static void	ft_free_split(char **box)
{
	int	i;

	i = 0;
	while (box[i])
	{
		free(box[i]);
		i++;
	}
	free(box);
}

char	**ft_split(char const *s, char c)
{
	char	**box;
	int		len_box;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	len_box = ft_count_words(s, c);
	box = (char **)malloc((len_box + 1) * sizeof(char *));
	if (!box)
		return (NULL);
	i = 0;
	start = 0;
	while (i < len_box)
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		box[i] = ft_substr(s, start, ft_count_char_start(s, c, start));
		if (!box[i])
			ft_free_split(box);
		i++;
		start += ft_count_char_start(s, c, start);
	}
	box[i] = NULL;
	return (box);
}
