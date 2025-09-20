/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:45:02 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/20 17:10:03 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_extension(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_RDONLY);
		close(fd);
		if ((path[len - 3] != 'b' && path[len - 2] != 'e'
				&& path[len - 1] != 'r'
				&& path[len - 4] != '.') || fd < 0)
			return (FAILURE);
		else
			return (SUCCESS);
	}
}

void	error_msg(char *str, t_data *data)
{
	if (data->map.map)
		ft_free(data->map.map);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(1);
}
