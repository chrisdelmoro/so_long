/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:58:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 18:29:45 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	t_game	data;

	input_validation(argc, argv[1]);
	initialize_vars(&data);
	map_validation(&data, argv[1]);
	initialize_window(&data);
	load_sprites(&data);
	mlx_loop_hook(data.mlx_ptr, &render_map, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, handle_x_click, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
