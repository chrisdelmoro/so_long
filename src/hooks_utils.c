/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:52:14 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 20:58:30 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	handle_keypress(int keysym, t_window *data)
{
	if (keysym == XK_Escape)
		destroy_imgs(data);
	if (keysym == XK_w)
		move_up(data);
	if (keysym == XK_a)
		move_left(data);
	if (keysym == XK_s)
		move_down(data);
	if (keysym == XK_d)
		move_right(data);
	return (0);
}

int	handle_x_click(t_window *data)
{
	destroy_imgs(data);
	return (0);
}
