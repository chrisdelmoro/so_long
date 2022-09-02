/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:49:38 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/02 20:12:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	flush_map(t_map *map)
{
	size_t	i;

	i = 0;
	while(map->lines[i])
	{
		free(map->lines[i]);
		map->lines[i] = NULL;
		i++;
	}
	free(map->lines);
	map->lines = NULL;
}
