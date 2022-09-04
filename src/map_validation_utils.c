/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 18:05:10 by ccamargo         ###   ########.fr       */
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
	//ft_printf("Number of lines: %d\n", map->line_count);
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
	{
		ft_printf("Map need to be at least 3 lines deep.\n");
		map->rectangle = 0;
	}
	while (map->lines[i])
	{
		if (ft_strlen(map->lines[0]) != ft_strlen(map->lines[i]))
		{
			ft_printf("Map is not a rectangle!\n");
			map->rectangle = 0;
		}
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
			{
				ft_printf("Invalid characters present on map file!\n");
				map->valid_chars = 0;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	map->valid_chars = 1;
}

static void check_wall_vert(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->lines[i])
	{
		if (map->lines[i][0] != '1' || map->lines[i][ft_strlen(map->lines[i]) - 1] != '1')
		{
			map->walled = 0;
			ft_printf("Map is not walled!\n");
			return ;
		}
		i++;
	}
	map->walled = 1;
}

static void	check_wall_hor(t_map *map)
{
	size_t	j;

	j = 0;
	while (map->lines[0][j])
	{
		if (map->lines[0][j] != '1')
		{
			map->walled = 0;
			ft_printf("Map is not walled!\n");
			return ;
		}
		j++;
	}
	j = 0;
	while (map->lines[(map->line_count) - 1][j])
	{
		if (map->lines[(map->line_count) - 1][j] != '1')
		{
			map->walled = 0;
			ft_printf("Map is not walled!\n");
			return ;
		}
		j++;
	}
}

static void	is_map_walled(t_map	*map)
{
	check_wall_vert(map);
	if (map->walled == 0)
		return ;
	check_wall_hor(map);
}

static void	validate_game_elements(t_map *map)
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
	if (map->exits < 1 || map->exits > 1)
		ft_printf("Map must have one and only one exit!\n");
	if (map->players < 1 || map->players > 1)
		ft_printf("Map must have one and only one player character!\n");
	if (map->collectables < 1)
		ft_printf("Map must have at least one collectable!\n");
}

void	map_validation(char *map_path)
{
	t_map	map;
	/* size_t	i; */

	initialize_map(&map);
	map.fd = open(map_path, O_RDONLY);
	if (map.fd < 0)
		ft_printf("Error! Failed to load map file!\n");
	count_lines(&map);
	map.lines = (char **) ft_calloc(map.line_count + 1, sizeof(char *));
	close(map.fd);
	map.fd = open(map_path, O_RDONLY);
	if (map.fd < 0)
		ft_printf("Error! Failed to load map file!\n");
	feed_lines(&map);
	is_map_rectangle(&map);
	are_map_chars_valid(&map);
	is_map_walled(&map);
	validate_game_elements(&map);
	/* i = 0;
	while (map.lines[i])
	{
		ft_printf("%d - %s\n", i + 1, map.lines[i]);
		i++;
	} */
	if (map.lines)
		flush_map(&map);
	close(map.fd);
}
