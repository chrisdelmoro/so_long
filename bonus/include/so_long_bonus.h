/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/11 19:31:53 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

# define VALID_MAP_CHARS	"EPKC10"

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

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_pixel;

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
	t_pixel	movements;
	t_img	player;
	t_img	enemy;
	t_img	collectable;
	t_img	exit;
	t_img	wall;
	t_img	background;
	t_map	map;
}				t_game;

/* Prototypes */

/* input_validation_utils_bonus.c */
void	input_validation(int argc, char *map_path);

/* initialization_utils_bonus.c */
void	load_sprites(t_game *data);
void	initialize_vars(t_game *data);

/* map_validation_utils_bonus.c */
void	map_validation(t_game *data, char *map_path);

/* map_validation_utils_2_bonus.c */
void	validate_game_elements(t_game *data);
void	is_map_walled(t_game *data);

/* map_validation_utils_3_bonus.c */
void	get_player_position(t_game *data);

/* close_utils_bonus.c */
void	error_occurred(char *err_msg, t_game *data);
void	flush_map(t_game *data);
void	close_game(t_game *data);

/* player_move_utils_bonus.c */
void	change_player_sprite(t_game *data, char *sprite_path);
void	move_up(t_game *data);
void	move_left(t_game *data);
void	move_down(t_game *data);
void	move_right(t_game *data);

/* player_move_utils_2_bonus.c */
void	walk_up(t_game *data);
void	walk_left(t_game *data);
void	walk_down(t_game *data);
void	walk_right(t_game *data);

/* hooks_utils_bonus.c */
int		handle_keypress(int keysym, t_game *data);
int		handle_x_click(t_game *data);

/* render_utils_bonus.c */
int		render_map(t_game *data);
void	initialize_window(t_game *data);

/* render_utils_bonus_2.c */
void	render_mov_board(t_game *data);
void	render_mov_count(t_game *data);

/* so_long_bonus.c */
int		handle_keypress(int keysym, t_game *data);

#endif