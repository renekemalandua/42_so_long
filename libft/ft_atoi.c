/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:40:12 by akemalan          #+#    #+#             */
/*   Updated: 2025/07/01 18:56:35 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	size_t	ft_skip_spaces(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;
	size_t	i;

	if (!nptr)
		return (0);
	sign = 1;
	result = 0;
	i = ft_skip_spaces(nptr);
	if ((nptr[i] == '-' || nptr[i] == '+')
		&& (nptr[i + 1] == '-' || nptr[i + 1] == '+'))
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
