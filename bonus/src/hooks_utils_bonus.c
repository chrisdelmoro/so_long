/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:52:14 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 12:42:57 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	handle_keypress(int keysym, t_game *data)
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

int	handle_x_click(t_game *data)
{
	destroy_imgs(data);
	return (0);
}
