/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:54:01 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 20:55:46 by ccamargo         ###   ########.fr       */
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
