/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:58:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/29 16:56:32 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

int	render(t_window *std_data)
{
	if (std_data->win_ptr == NULL)
		return (1);
	//Render stuff
	//img_pixel_put(&std_data->img, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, RED_PIXEL);
	mlx_put_image_to_window(std_data->mlx_ptr, std_data->win_ptr, std_data->img.mlx_img, 0, 0);
	return (0);
}


int	handle_keypress(int keysym, t_window *std_data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(std_data->mlx_ptr, std_data->win_ptr);
		std_data->win_ptr = NULL;
	}
	/* if (keysym == XK_a)
	{
		mlx_string_put(std_data->mlx_ptr, std_data->win_ptr, 5, 5, RED_PIXEL, "Testando String!");
	} */
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_buttonpress(int keysym, t_window *std_data)
{
	if (keysym == Button1)
		ft_printf("Mouse 1 click!\n");
	return (0);
}

int main(void)
{
	t_window	std_data;

	std_data.mlx_ptr = mlx_init();
	if (!std_data.mlx_ptr)
		return (1);
	std_data.win_ptr = mlx_new_window(std_data.mlx_ptr, 800, 600, "My First Window!");
	if (!std_data.win_ptr)
	{
		ft_freethis((char**)&std_data.win_ptr, NULL);
		return (1);
	}

	/* Setup hooks */ 
	std_data.img.mlx_img = mlx_new_image(std_data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	std_data.img.addr = mlx_get_data_addr(std_data.img.mlx_img, &std_data.img.bpp,
			&std_data.img.line_len, &std_data.img.endian);

	mlx_loop_hook(std_data.mlx_ptr, &render, &std_data);
	mlx_hook(std_data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &std_data);
	mlx_string_put(std_data.mlx_ptr, std_data.win_ptr, 5, 5, RED_PIXEL, "Testando String!");
	//mlx_hook(std_data.win_ptr, Button1, Button1Mask, &handle_buttonpress, &std_data);
	//mlx_mouse_hook(std_data.win_ptr, handle_buttonpress, &std_data);

	mlx_loop(std_data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(std_data.mlx_ptr, std_data.img.mlx_img);
	mlx_destroy_display(std_data.mlx_ptr);
	ft_freethis((char **)&std_data.mlx_ptr, NULL);
	return (0);
}
