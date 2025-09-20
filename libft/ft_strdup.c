/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:45:32 by akemalan          #+#    #+#             */
/*   Updated: 2025/07/02 18:55:20 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stddef.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
