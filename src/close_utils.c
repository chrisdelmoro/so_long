/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:49:38 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 11:19:20 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	error_occurred(char *err_msg, t_game *data)
{
	ft_printf("%s\n", err_msg);
	flush_map(data);
	exit(0);
}

void	flush_map(t_game *data)
{
	size_t	i;

	i = 0;
	if (data->map.lines)
	{
		while (data->map.lines[i])
		{
			free(data->map.lines[i]);
			data->map.lines[i] = NULL;
			i++;
		}
		free(data->map.lines);
		data->map.lines = NULL;
	}
}

void	destroy_imgs(t_game *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player.sprite_img);
	mlx_destroy_image(data->mlx_ptr, data->collectable.sprite_img);
	mlx_destroy_image(data->mlx_ptr, data->exit.sprite_img);
	mlx_destroy_image(data->mlx_ptr, data->wall.sprite_img);
	mlx_destroy_image(data->mlx_ptr, data->background.sprite_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
}
