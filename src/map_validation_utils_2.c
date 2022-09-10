/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:14:46 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 21:13:11 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	check_wall_vert(t_window *data)
{
	size_t	i;

	i = 0;
	while (data->map.lines[i])
	{
		if (data->map.lines[i][0] != '1' || data->map.lines[i][ft_strlen(data->\
map.lines[i]) \
		- 1] != '1')
			error_occurred("Error\nMap is not walled!", data);
		i++;
	}
}

static void	check_wall_hor(t_window *data)
{
	size_t	j;

	j = 0;
	while (data->map.lines[0][j])
	{
		if (data->map.lines[0][j] != '1')
			error_occurred("Error\nMap is not walled!", data);
		j++;
	}
	j = 0;
	while (data->map.lines[(data->map.line_count) - 1][j])
	{
		if (data->map.lines[(data->map.line_count) - 1][j] != '1')
			error_occurred("Error\nMap is not walled!", data);
		j++;
	}
	data->map.walled = 1;
}

void	is_map_walled(t_window *data)
{
	check_wall_vert(data);
	check_wall_hor(data);
}

static void	validate_game_elements_error(t_window *data)
{
	if (data->map.exit_count < 1)
		error_occurred("Error\nMap must have at least one exit!", data);
	if (data->map.exit_count > 1)
		error_occurred("Error\nMap must have only one exit!", data);
	if (data->map.player_count < 1)
		error_occurred("Error\nMap must have at least one player character!", \
		data);
	if (data->map.player_count > 1)
		error_occurred("Error\nMap must have only one player character!", data);
	if (data->map.collectable_count < 1)
		error_occurred("Error\nMap must have at least one collectable!", data);
}

void	validate_game_elements(t_window *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.lines[i])
	{
		while (data->map.lines[i][j])
		{
			if (data->map.lines[i][j] == 'E')
				data->map.exit_count++;
			if (data->map.lines[i][j] == 'P')
				data->map.player_count++;
			if (data->map.lines[i][j] == 'C')
				data->map.collectable_count++;
			j++;
		}
		j = 0;
		i++;
	}
	validate_game_elements_error(data);
}
