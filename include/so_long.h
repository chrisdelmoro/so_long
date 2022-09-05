/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 21:18:20 by ccamargo         ###   ########.fr       */
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
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_window;

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
	char	**lines;
}				t_map;

/* Prototypes */

/* input_validation_utils.c */
int		input_validation(int argc, char *map_path);

/* initialization_utils.c */
void	initialize_map(t_map *map);

/* map_validation_utils.c */
void	map_validation(t_map *map, char *map_path);

/* map_validation_utils_2.c */
void	validate_game_elements(t_map *map);
void	is_map_walled(t_map	*map);

/* close_utils.c */
void	error_occurred(char *err_msg, t_map *map);
void	flush_map(t_map *map);

#endif