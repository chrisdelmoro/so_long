/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 21:11:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	count_lines(t_window *data)
{
	char	*gnl_line;

	gnl_line = get_next_line(data->map.fd);
	while (gnl_line)
	{
		data->map.line_count++;
		ft_freethis(&gnl_line, NULL);
		gnl_line = get_next_line(data->map.fd);
	}
	ft_freethis(&gnl_line, NULL);
}

static void	feed_lines(t_window *data)
{
	char	*gnl_line;
	char	*treated_line;
	size_t	i;

	i = 0;
	gnl_line = get_next_line(data->map.fd);
	while (gnl_line)
	{
		if (ft_strrchr(gnl_line, '\n'))
		{
			treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') \
			- gnl_line);
			ft_freethis(&gnl_line, NULL);
			data->map.lines[i] = treated_line;
		}
		else
			data->map.lines[i] = gnl_line;
		gnl_line = get_next_line(data->map.fd);
		i++;
	}
	ft_freethis(&gnl_line, NULL);
}

static void	is_map_rectangle(t_window *data)
{
	size_t	i;

	i = 1;
	if (data->map.line_count < 3)
		error_occurred("Error\nMap need to be at least 3 lines deep.", data);
	while (data->map.lines[i])
	{
		if (ft_strlen(data->map.lines[0]) != ft_strlen(data->map.lines[i]))
			error_occurred("Error\nMap is not a rectangle!", data);
		i++;
	}
	data->map.rectangle = 1;
}

static void	are_map_chars_valid(t_window *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.lines[i])
	{
		while (data->map.lines[i][j])
		{
			if (!ft_strchr(VALID_MAP_CHARS, data->map.lines[i][j]))
				error_occurred("Error\nInvalid characters present on map \
file!\nOnly 'EPC10' are valid characters!", data);
			j++;
		}
		j = 0;
		i++;
	}
	data->map.valid_chars = 1;
}

void	map_validation(t_window *data, char *map_path)
{
	data->map.fd = open(map_path, O_RDONLY);
	if (data->map.fd < 0)
		error_occurred("Error\nFailed to load map file!", data);
	count_lines(data);
	data->map.lines = (char **) ft_calloc(data->map.line_count + 1, \
sizeof(char *));
	close(data->map.fd);
	data->map.fd = open(map_path, O_RDONLY);
	if (data->map.fd < 0)
		error_occurred("Error\nFailed to load map file!", data);
	feed_lines(data);
	close(data->map.fd);
	is_map_rectangle(data);
	are_map_chars_valid(data);
	is_map_walled(data);
	validate_game_elements(data);
	get_player_position(data);
}
