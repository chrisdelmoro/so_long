/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils_bonus_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:06:54 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 22:13:38 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	walk_up(t_game *data)
{
	data->map.lines[data->map.player_line][data->map.player_collum] = '0';
	data->map.lines[data->map.player_line - 1][data->map.player_collum] = 'P';
	data->map.player_line--;
	change_player_sprite(data, "./resources/images/link_back.xpm");
}

void	walk_left(t_game *data)
{
	data->map.lines[data->map.player_line][data->map.player_collum] = '0';
	data->map.lines[data->map.player_line][data->map.player_collum - 1] = 'P';
	data->map.player_collum--;
	change_player_sprite(data, "./resources/images/link_left.xpm");
}

void	walk_down(t_game *data)
{
	data->map.lines[data->map.player_line][data->map.player_collum] = '0';
	data->map.lines[data->map.player_line + 1][data->map.player_collum] = 'P';
	data->map.player_line++;
	change_player_sprite(data, "./resources/images/link_front.xpm");
}

void	walk_right(t_game *data)
{
	data->map.lines[data->map.player_line][data->map.player_collum] = '0';
	data->map.lines[data->map.player_line][data->map.player_collum + 1] = 'P';
	data->map.player_collum++;
	change_player_sprite(data, "./resources/images/link_right.xpm");
}
