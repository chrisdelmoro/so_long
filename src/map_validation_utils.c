/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/03 19:45:13 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	count_lines(t_map *map)
{
	int		read_return;
	char	c;

	map->line_count = 0;
	read_return = read(map->fd, &c, 1);
	while (read_return > 0)
	{
		if (c == '\n')
			map->line_count++;
		read_return = read(map->fd, &c, 1);
	}
	map->line_count++;
	ft_printf("Number of lines: %d\n", map->line_count);
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
			treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') - gnl_line);
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

void	map_validation(char *map_path)
{
	t_map	map;
	/* size_t	i; */

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