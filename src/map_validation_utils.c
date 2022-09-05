/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 21:14:24 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	count_lines(t_map *map)
{
	char	*gnl_line;

	gnl_line = get_next_line(map->fd);
	while (gnl_line)
	{
		map->line_count++;
		ft_freethis(&gnl_line, NULL);
		gnl_line = get_next_line(map->fd);
	}
	ft_freethis(&gnl_line, NULL);
}

static void	feed_lines(t_map *map)
{
	char	*gnl_line;
	char	*treated_line;
	size_t	i;

	i = 0;
	gnl_line = get_next_line(map->fd);
	while (gnl_line)
	{
		if (ft_strrchr(gnl_line, '\n'))
		{
			treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') \
			- gnl_line);
			ft_freethis(&gnl_line, NULL);
			map->lines[i] = treated_line;
		}
		else
			map->lines[i] = gnl_line;
		gnl_line = get_next_line(map->fd);
		i++;
	}
	ft_freethis(&gnl_line, NULL);
}

static void	is_map_rectangle(t_map *map)
{
	size_t	i;

	i = 1;
	if (map->line_count < 3)
		error_occurred("Map need to be at least 3 lines deep.", map);
	while (map->lines[i])
	{
		if (ft_strlen(map->lines[0]) != ft_strlen(map->lines[i]))
			error_occurred("Map is not a rectangle!", map);
		i++;
	}
	map->rectangle = 1;
}

static void	are_map_chars_valid(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->lines[i])
	{
		while (map->lines[i][j])
		{
			if (!ft_strchr(VALID_MAP_CHARS, map->lines[i][j]))
				error_occurred("Invalid characters present on map file!\n\
Only 'EPC10' are valid characters!", map);
			j++;
		}
		j = 0;
		i++;
	}
	map->valid_chars = 1;
}

void	map_validation(t_map *map, char *map_path)
{
	initialize_map(map);
	map->fd = open(map_path, O_RDONLY);
	if (map->fd < 0)
		error_occurred("Error! Failed to load map file!", map);
	count_lines(map);
	map->lines = (char **) ft_calloc(map->line_count + 1, sizeof(char *));
	close(map->fd);
	map->fd = open(map_path, O_RDONLY);
	if (map->fd < 0)
		error_occurred("Error! Failed to load map file!", map);
	feed_lines(map);
	close(map->fd);
	is_map_rectangle(map);
	are_map_chars_valid(map);
	is_map_walled(map);
	validate_game_elements(map);
}
