/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:30:39 by akemalan          #+#    #+#             */
/*   Updated: 2025/07/01 16:29:37 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include "libft.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	real_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if ((ft_strlen(s) - start) < len)
		real_len = ft_strlen(s) - start;
	else
		real_len = len;
	ptr = (char *)malloc(real_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (s + start), (real_len + 1));
	return (ptr);
}
