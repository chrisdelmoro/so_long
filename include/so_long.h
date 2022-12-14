/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 18:28:07 by ccamargo         ###   ########.fr       */
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
	int		collectable_count;
	int		player_count;
	int		exit_count;
	int		line_count;
	int		collum_count;
	int		player_line;
	int		player_collum;
	char	**lines;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		score;
	int		move_count;
	t_img	player;
	t_img	collectable;
	t_img	exit;
	t_img	wall;
	t_img	background;
	t_map	map;
}				t_game;

/* Prototypes */

/* input_validation_utils.c */
void	input_validation(int argc, char *map_path);

/* initialization_utils.c */
void	load_sprites(t_game *data);
void	initialize_vars(t_game *data);

/* map_validation_utils.c */
void	map_validation(t_game *data, char *map_path);

/* map_validation_utils_2.c */
void	validate_game_elements(t_game *data);
void	is_map_walled(t_game *data);

/* map_validation_utils_3.c */
void	get_player_position(t_game *data);

/* close_utils.c */
void	error_occurred(char *err_msg, t_game *data);
void	flush_map(t_game *data);
void	close_game(t_game *data);

/* player_move_utils.c */
void	move_up(t_game *data);
void	move_left(t_game *data);
void	move_down(t_game *data);
void	move_right(t_game *data);

/* hooks_utils.c */
int		handle_keypress(int keysym, t_game *data);
int		handle_x_click(t_game *data);

/* render_utils.c */
int		render_map(t_game *data);
void	initialize_window(t_game *data);

/* so_long.c */
int		handle_keypress(int keysym, t_game *data);

#endif