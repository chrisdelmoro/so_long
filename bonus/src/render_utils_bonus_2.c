/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:27:36 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/11 19:36:33 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->movements.addr + (y * data->movements.line_len + x * \
	(data->movements.bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_mov_board(t_game *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < 128)
	{
		y = 0;
		while (y < 54)
		{
			if ((y > 4 && y < 49) && (x > 4 && x < 124))
				my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			else
				my_mlx_pixel_put(data, x, y, 0x704848);
			y++;
		}
		x++;
	}
}

void	render_mov_count(t_game *data)
{
	char	*mov_str;
	char	*mov_count;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->movements.img, 64, 5);
	mov_count = ft_itoa(data->move_count);
	mov_str = ft_strjoin("Movements: ", mov_count);
	ft_freethis(&mov_count, NULL);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 90, 36, 0x704848, mov_str);
	ft_freethis(&mov_str, NULL);
}
