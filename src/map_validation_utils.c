/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/03 18:55:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static size_t	count_lines(int fd)
{
	int		read_return;
	char	c;
	size_t	i;

	read_return = read(fd, &c, 1);
	i = 0;
	while (read_return > 0)
	{
		if (c == '\n')
			i++;
		read_return = read(fd, &c, 1);
	}
	i++;
	//ft_printf("Number of lines: %d\n", i);
	return (i);
}

static void	feed_lines(t_map *map, int fd)
{
	char	*gnl_line;
	char	*treated_line;
	size_t	i;

	i = 0;
	gnl_line = get_next_line(fd);
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
		gnl_line = get_next_line(fd);
		i++;
	}
	ft_freethis(&gnl_line, NULL);
}

static int	is_map_rectangle(t_map *map, int line_count)
{
	size_t	i;

	i = 1;
	if (line_count < 3)
	{
		ft_printf("Map need to be at least 3 lines deep.\n");
		//flush_map(map);
		return (0);
	}
	while (map->lines[i])
	{
		if (ft_strlen(map->lines[0]) != ft_strlen(map->lines[i]))
		{
			ft_printf("Map is not a rectangle!\n");
			//flush_map(map);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	are_map_chars_valid(t_map *map)
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
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	map_validation(char *map_path)
{
	int		fd;
	int		line_count;
	t_map	map;
	//size_t	i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error! Failed to load map file!\n");
	line_count = count_lines(fd);
	map.lines = (char **) ft_calloc(line_count + 1, sizeof(char *));
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error! Failed to load map file!\n");
	feed_lines(&map, fd);
	map.rectangle = is_map_rectangle(&map, line_count);
	map.valid_chars = are_map_chars_valid(&map);
	/* i = 0;
	while (map.lines[i])
	{
		ft_printf("%d - %s\n", i + 1, map.lines[i]);
		i++;
	} */
	if (map.lines)
		flush_map(&map);
	close(fd);
}