/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:42:17 by akemalan          #+#    #+#             */
/*   Updated: 2025/06/26 17:40:03 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "libft.h"
#include<stddef.h>

size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_fill_number(char *str, int n, int len, int is_negative)
{
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		if (n == 0 && is_negative && len > 0)
		{
			str[--len] = '-';
			break ;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_negative;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	len = ft_count_digits(n) + is_negative;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_fill_number(str, n, len, is_negative);
	return (str);
}
