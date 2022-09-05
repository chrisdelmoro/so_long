/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:49:38 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 20:57:30 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	error_occurred(char *err_msg, t_map *map)
{
	ft_printf("%s\n", err_msg);
	flush_map(map);
	exit(0);
}

void	flush_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->lines)
	{
		while (map->lines[i])
		{
			free(map->lines[i]);
			map->lines[i] = NULL;
			i++;
		}
		free(map->lines);
		map->lines = NULL;
	}
}
