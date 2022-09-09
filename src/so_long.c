/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:58:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 14:32:40 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	check_sprite_position(t_window *data, size_t i, size_t j)
{
	if (data->map.lines[j][i] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->wall.sprite_img, i * 64, j * 64);
	if (data->map.lines[j][i] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->background.sprite_img, i * 64, j * 64);
	if (data->map.lines[j][i] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->player.sprite_img, i * 64, j * 64);
	if (data->map.lines[j][i] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->collectable.sprite_img, i * 64, j * 64);
	if (data->map.lines[j][i] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->exit.sprite_img, i * 64, j * 64);
}

int	render_map(t_window *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (j < (size_t) data->map.line_count)
	{
		while (i < (size_t) data->map.collum_count)
		{
			check_sprite_position(data, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->wall.sprite_img, 0, 0);
	return (0);
}

void	initialize_window(t_window *data)
{
	data->map.collum_count = ft_strlen(data->map.lines[0]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.collum_count * 64, \
	data->map.line_count * 64, "so_long");
}

int	handle_keypress(int keysym, t_window *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
		mlx_destroy_image(data->mlx_ptr, data->collectable.sprite_img);
		mlx_destroy_image(data->mlx_ptr, data->exit.sprite_img);
		mlx_destroy_image(data->mlx_ptr, data->wall.sprite_img);
		mlx_destroy_image(data->mlx_ptr, data->background.sprite_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_w)
	{
		move_up(data);
	}
	if (keysym == XK_a)
	{
		move_left(data);
	}
	if (keysym == XK_s)
	{
		move_down(data);
	}
	if (keysym == XK_d)
	{
		move_right(data);
	}
	//ft_printf("Keypress: %d\n", keysym);
	return (0);
}

static void	get_player_position(t_window *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.lines[i])
	{
		while (data->map.lines[i][j])
		{
			if (data->map.lines[i][j] == 'P')
			{
				data->map.player_line = i;
				data->map.player_collum = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_window	data;

	input_validation(argc, argv[1]);
	initialize_vars(&data);
	map_validation(&data, argv[1]);
	get_player_position(&data);
	initialize_window(&data);
	load_sprites(&data);
	mlx_loop_hook(data.mlx_ptr, &render_map, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	ft_freethis((char **) &data.mlx_ptr, NULL);
	flush_map(&data);
	return (0);
}
