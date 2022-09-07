/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/07 18:17:09 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* MiniLibX Library */
# include <mlx.h>

/* Xlib keycode - keysymbol mapping, events and masks */
# include <X11/keysym.h>
# include <X11/X.h>

/* Libft */
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

/* open() function includes */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* read() and close() include */
# include <unistd.h>

/* Constants */

# define VALID_MAP_CHARS	"EPC10"

/* Structs */

typedef struct s_img
{
	void	*sprite_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	int		fd;
	int		rectangle;
	int		valid_chars;
	int		walled;
	int		collectables;
	int		players;
	int		exits;
	int		line_count;
	int		collum_count;
	char	**lines;
}				t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	player;
	t_img	collectable;
	t_img	exit;
	t_img	wall;
	t_img	background;
	t_map	map;
}				t_window;

/* Prototypes */

/* input_validation_utils.c */
void	input_validation(int argc, char *map_path);

/* initialization_utils.c */
void	initialize_map(t_window *data);
void	load_sprites(t_window *data);

/* map_validation_utils.c */
void	map_validation(t_window *data, char *map_path);

/* map_validation_utils_2.c */
void	validate_game_elements(t_window *data);
void	is_map_walled(t_window *data);

/* close_utils.c */
void	error_occurred(char *err_msg, t_window *data);
void	flush_map(t_window *data);

#endif