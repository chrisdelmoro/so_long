/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/02 12:08:51 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static size_t	count_lines(int fd)
{
	char	c;
	size_t	i;
	
	i = read(fd, &c, 1);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	//ft_printf("Number of lines: %d\n", i);
	return (i);
}

static void	feed_lines(char ***lines, int fd)
{
	char	*gnl_line;
	char	*treated_line;
	size_t	i;

	i = 0;
	gnl_line = get_next_line(fd);
	while (gnl_line)
	{
		treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') - gnl_line);
		ft_freethis(&gnl_line, NULL);
		lines[0][i] = treated_line;
		gnl_line = get_next_line(fd);
		i++;
	}
}

static int	validate_square(char ***lines, int line_count)
{
	size_t	i;

	i = 1;
	if (line_count < 3)
	{
		ft_printf("Map need to be at least 3 lines deep.\n");
		flush(lines);
		return (0);
	}
	while (lines[0][i])
	{	
		if (ft_strlen(lines[0][0]) != ft_strlen(lines[0][i]))
		{
			ft_printf("Map is not a rectangle!\n");
			flush(lines);
			return (0);
		}
		i++;
	}
	return (1);
}

void	map_validation(char *map_path)
{
	int		fd;
	int		line_count;
	char	**lines;
	size_t	i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error! Failed to load map file!\n");
	line_count = count_lines(fd);
	lines = (char **) ft_calloc(line_count + 1, sizeof(char *));
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error! Failed to load map file!\n");
	feed_lines(&lines, fd);
	i = 0;
	validate_square(&lines, line_count);
	while (lines[i])
	{
		ft_printf("%d - %s\n", i + 1, lines[i]);
		i++;
	}
	ft_printf("lines point to: %p\n", lines);
	close(fd);
}