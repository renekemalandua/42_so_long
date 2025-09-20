/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 06:57:26 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/04 07:09:54 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *str, const char *end, size_t n)
{
	size_t	len;

	len = 0;
	if (!str || !end)
		return (-1);
	len = ft_strlen(str);
	if (len < n)
		return (-1);
	return (ft_strncmp((str + len - n), end, n));
}
