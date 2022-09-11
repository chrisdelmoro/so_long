/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:00:24 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 22:15:24 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	change_player_sprite(t_game *data, char *sprite_path)
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

void	move_up(t_game *data)
{
	if (data->map.lines[data->map.player_line - 1] \
	[data->map.player_collum] != '1')
	{
		if (data->map.lines[data->map.player_line - 1] \
		[data->map.player_collum] != 'E')
		{
			if (data->map.lines[data->map.player_line - 1] \
			[data->map.player_collum] == 'C')
				data->score++;
			if (data->map.lines[data->map.player_line - 1] \
			[data->map.player_collum] == 'K')
			{
				ft_printf("You died! :(\n");
				close_game(data);
			}
			walk_up(data);
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			close_game(data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}

void	move_left(t_game *data)
{
	if (data->map.lines[data->map.player_line] \
	[data->map.player_collum - 1] != '1')
	{
		if (data->map.lines[data->map.player_line] \
		[data->map.player_collum - 1] != 'E')
		{
			if (data->map.lines[data->map.player_line] \
			[data->map.player_collum - 1] == 'C')
				data->score++;
			if (data->map.lines[data->map.player_line] \
			[data->map.player_collum - 1] == 'K')
			{
				ft_printf("You died! :(\n");
				close_game(data);
			}
			walk_left(data);
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			close_game(data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}

void	move_down(t_game *data)
{
	if (data->map.lines[data->map.player_line + 1] \
	[data->map.player_collum] != '1')
	{
		if (data->map.lines[data->map.player_line + 1] \
		[data->map.player_collum] != 'E')
		{
			if (data->map.lines[data->map.player_line + 1] \
			[data->map.player_collum] == 'C')
				data->score++;
			if (data->map.lines[data->map.player_line + 1] \
			[data->map.player_collum] == 'K')
			{
				ft_printf("You died! :(\n");
				close_game(data);
			}
			walk_down(data);
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			close_game(data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}

void	move_right(t_game *data)
{
	if (data->map.lines[data->map.player_line] \
	[data->map.player_collum + 1] != '1')
	{
		if (data->map.lines[data->map.player_line] \
		[data->map.player_collum + 1] != 'E')
		{
			if (data->map.lines[data->map.player_line] \
			[data->map.player_collum + 1] == 'C')
				data->score++;
			if (data->map.lines[data->map.player_line] \
			[data->map.player_collum + 1] == 'K')
			{
				ft_printf("You died! :(\n");
				close_game(data);
			}
			walk_right(data);
		}
		else if (data->score == data->map.collectable_count)
		{
			ft_printf("Final Score: %d\n", data->score);
			close_game(data);
		}
		else
			ft_printf("Not all rupies were collected!\n");
	}
}
