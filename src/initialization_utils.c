/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:38:32 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 11:18:53 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	initialize_map(t_game *data)
{
	data->map.fd = -1;
	data->map.rectangle = 0;
	data->map.valid_chars = 0;
	data->map.walled = 0;
	data->map.collectable_count = 0;
	data->map.player_count = 0;
	data->map.exit_count = 0;
	data->map.line_count = 0;
	data->map.collum_count = 0;
	data->map.player_line = 0;
	data->map.player_collum = 0;
	data->map.lines = NULL;
}

static void	initialize_game_stats(t_game *data)
{
	data->score = 0;
	data->move_count = 0;
}

static void	load_sprites_2(t_game *data)
{
	data->background.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./resources/images/background_zelda.xpm", &data->background.width, \
	&data->background.height);
	data->background.addr = mlx_get_data_addr(data->background.sprite_img, \
	&data->background.bpp, &data->background.line_len, \
	&data->background.endian);
	data->wall.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./resources/images/wall_zelda.xpm", &data->wall.width, \
	&data->wall.height);
	data->wall.addr = mlx_get_data_addr(data->wall.sprite_img, \
	&data->wall.bpp, &data->wall.line_len, &data->wall.endian);
	data->collectable.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./resources/images/collectable.xpm", &data->collectable.width, \
	&data->collectable.height);
	data->collectable.addr = mlx_get_data_addr(data->collectable.sprite_img, \
	&data->collectable.bpp, &data->collectable.line_len, \
	&data->collectable.endian);
	data->exit.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./resources/images/exit_zelda.xpm", &data->exit.width, \
	&data->exit.height);
	data->exit.addr = mlx_get_data_addr(data->exit.sprite_img, \
	&data->exit.bpp, &data->exit.line_len, &data->exit.endian);
}

void	load_sprites(t_game *data)
{
	data->player.sprite_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./resources/images/link_front.xpm", &data->player.width, \
	&data->player.height);
	data->player.addr = mlx_get_data_addr(data->player.sprite_img, \
	&data->player.bpp, &data->player.line_len, &data->player.endian);
	load_sprites_2(data);
}

void	initialize_vars(t_game *data)
{
	initialize_map(data);
	initialize_game_stats(data);
}
