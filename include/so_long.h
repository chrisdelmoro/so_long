/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/24 22:42:50 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_window;

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define BLUE_PIXEL 0x000000FF