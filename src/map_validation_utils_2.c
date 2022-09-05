/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:14:46 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 21:18:01 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	check_wall_vert(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->lines[i])
	{
		if (map->lines[i][0] != '1' || map->lines[i][ft_strlen(map->lines[i]) \
		- 1] != '1')
			error_occurred("Map is not walled!", map);
		i++;
	}
}

static void	check_wall_hor(t_map *map)
{
	size_t	j;

	j = 0;
	while (map->lines[0][j])
	{
		if (map->lines[0][j] != '1')
			error_occurred("Map is not walled!", map);
		j++;
	}
	j = 0;
	while (map->lines[(map->line_count) - 1][j])
	{
		if (map->lines[(map->line_count) - 1][j] != '1')
			error_occurred("Map is not walled!", map);
		j++;
	}
	map->walled = 1;
}

void	is_map_walled(t_map	*map)
{
	check_wall_vert(map);
	check_wall_hor(map);
}

static void	validate_game_elements_error(t_map *map)
{
	if (map->exits < 1)
		error_occurred("Map must have at least one exit!", map);
	if (map->exits > 1)
		error_occurred("Map must have only one exit!", map);
	if (map->players < 1)
		error_occurred("Map must have at least one player character!", map);
	if (map->players > 1)
		error_occurred("Map must have only one player character!", map);
	if (map->collectables < 1)
		error_occurred("Map must have at least one collectable!", map);
}

void	validate_game_elements(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->lines[i])
	{
		while (map->lines[i][j])
		{
			if (map->lines[i][j] == 'E')
				map->exits++;
			if (map->lines[i][j] == 'P')
				map->players++;
			if (map->lines[i][j] == 'C')
				map->collectables++;
			j++;
		}
		j = 0;
		i++;
	}
	validate_game_elements_error(map);
}
