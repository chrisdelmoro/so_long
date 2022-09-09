/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:00:24 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 14:47:43 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	change_player_sprite(t_window *data, char *sprite_path)
{
	mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
	data->player.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	sprite_path, &data->player.width, \
	&data->player.height);
	data->player.addr = mlx_get_data_addr(data->player.sprite_img, \
	&data->player.bpp, &data->player.line_len, &data->player.endian);
	data->move_count++;
	ft_printf("Movements: %d\n", data->move_count);
}

void	move_up(t_window *data)
{
	if (data->map.lines[data->map.player_line - 1][data->map.player_collum] != '1')
	{
		if (data->map.lines[data->map.player_line - 1][data->map.player_collum] != 'E')
		{
			if (data->map.lines[data->map.player_line - 1][data->map.player_collum] == 'C')
				data->score++;
			data->map.lines[data->map.player_line][data->map.player_collum] = '0';
			data->map.lines[data->map.player_line - 1][data->map.player_collum] = 'P';
			data->map.player_line--;
			change_player_sprite(data, "./resources/images/link_back.xpm");
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			handle_keypress(XK_Escape, data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}

void	move_left(t_window *data)
{
	if (data->map.lines[data->map.player_line][data->map.player_collum - 1] != '1')
	{
		if (data->map.lines[data->map.player_line][data->map.player_collum - 1] != 'E')
		{
			if (data->map.lines[data->map.player_line][data->map.player_collum - 1] == 'C')
				data->score++;
			data->map.lines[data->map.player_line][data->map.player_collum] = '0';
			data->map.lines[data->map.player_line][data->map.player_collum - 1] = 'P';
			data->map.player_collum--;
			change_player_sprite(data, "./resources/images/link_left.xpm");
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			handle_keypress(XK_Escape, data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}

void	move_down(t_window *data)
{
	if (data->map.lines[data->map.player_line + 1][data->map.player_collum] != '1')
	{
		if (data->map.lines[data->map.player_line + 1][data->map.player_collum] != 'E')
		{
			if (data->map.lines[data->map.player_line + 1][data->map.player_collum] == 'C')
				data->score++;
			data->map.lines[data->map.player_line][data->map.player_collum] = '0';
			data->map.lines[data->map.player_line + 1][data->map.player_collum] = 'P';
			data->map.player_line++;
			change_player_sprite(data, "./resources/images/link_front.xpm");
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			handle_keypress(XK_Escape, data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}

void	move_right(t_window *data)
{
	if (data->map.lines[data->map.player_line][data->map.player_collum + 1] != '1')
	{
		if (data->map.lines[data->map.player_line][data->map.player_collum + 1] != 'E')
		{
			if (data->map.lines[data->map.player_line][data->map.player_collum + 1] == 'C')
				data->score++;
			data->map.lines[data->map.player_line][data->map.player_collum] = '0';
			data->map.lines[data->map.player_line][data->map.player_collum + 1] = 'P';
			data->map.player_collum++;
			change_player_sprite(data, "./resources/images/link_right.xpm");
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			handle_keypress(XK_Escape, data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}