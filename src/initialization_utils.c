/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:38:32 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 20:54:00 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	initialize_map(t_map *map)
{
	map->fd = -1;
	map->rectangle = 0;
	map->valid_chars = 0;
	map->walled = 0;
	map->collectables = 0;
	map->players = 0;
	map->exits = 0;
	map->line_count = 0;
	map->lines = NULL;
}
