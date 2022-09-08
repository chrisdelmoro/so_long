/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:00:24 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/08 16:46:04 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void move_up(t_window *data)
{
	if (data->map.lines[data->map.player_line - 1][data->map.player_collum] != '1')
	{
		data->map.lines[data->map.player_line][data->map.player_collum] = '0';
		data->map.lines[data->map.player_line - 1][data->map.player_collum] = 'P';
		data->map.player_line--;
		mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
		data->player.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./resources/images/link_back.xpm", &data->player.width, \
		&data->player.height);
		data->player.addr = mlx_get_data_addr(data->player.sprite_img, \
		&data->player.bpp, &data->player.line_len, &data->player.endian);
		ft_printf("Player_line: %d / Player_collum: %d\n", data->map.player_line, data->map.player_collum);
	}
}

void move_left(t_window *data)
{
	if (data->map.lines[data->map.player_line][data->map.player_collum - 1] != '1')
	{
		data->map.lines[data->map.player_line][data->map.player_collum] = '0';
		data->map.lines[data->map.player_line ][data->map.player_collum - 1] = 'P';
		data->map.player_collum--;
		mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
		data->player.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./resources/images/link_left.xpm", &data->player.width, \
		&data->player.height);
		data->player.addr = mlx_get_data_addr(data->player.sprite_img, \
		&data->player.bpp, &data->player.line_len, &data->player.endian);
		ft_printf("Player_line: %d / Player_collum: %d\n", data->map.player_line, data->map.player_collum);
	}
}

void move_down(t_window *data)
{
	if (data->map.lines[data->map.player_line + 1][data->map.player_collum] != '1')
	{
		data->map.lines[data->map.player_line][data->map.player_collum] = '0';
		data->map.lines[data->map.player_line + 1][data->map.player_collum] = 'P';
		data->map.player_line++;
		mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
		data->player.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./resources/images/link_front.xpm", &data->player.width, \
		&data->player.height);
		data->player.addr = mlx_get_data_addr(data->player.sprite_img, \
		&data->player.bpp, &data->player.line_len, &data->player.endian);
		ft_printf("Player_line: %d / Player_collum: %d\n", data->map.player_line, data->map.player_collum);
	}
}

void move_right(t_window *data)
{
	if (data->map.lines[data->map.player_line][data->map.player_collum + 1] != '1')
	{
		data->map.lines[data->map.player_line][data->map.player_collum] = '0';
		data->map.lines[data->map.player_line][data->map.player_collum + 1] = 'P';
		data->map.player_collum++;
		mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
		data->player.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./resources/images/link_right.xpm", &data->player.width, \
		&data->player.height);
		data->player.addr = mlx_get_data_addr(data->player.sprite_img, \
		&data->player.bpp, &data->player.line_len, &data->player.endian);
		ft_printf("Player_line: %d / Player_collum: %d\n", data->map.player_line, data->map.player_collum);
	}
}