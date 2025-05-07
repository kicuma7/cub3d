/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/07 12:45:48 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libs/libft/inc/libft.h"
# include "../libs/mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

# ifndef MAX_TEXTURE_PATH
#  define MAX_TEXTURE_PATH 256 // Define o tamanho máximo para o caminho de textura
# endif
# define PIXELS 30
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef	struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	t_point		center;
	char		cardinal_point;
}				t_player;

typedef struct	s_img
{
	void		*img;
	int			size_line;
	int			*img_addr;
	size_t		pixels_wid;
	size_t		pixels_hei;
}				t_img;

typedef struct s_map
{
	int		hei;
	int		wid;
	char	**map;
	char	**texture;
	char	**color;
	char	*e;
	char	*s;
	char 	*w;
	char 	*n;
	size_t	max_len;
	size_t	pixels_wid;
	size_t	pixels_hei;
}			t_map;

typedef struct s_mlx
{
	void		*con;
	void		*win;
	int			floor_set;
	int			ceiling_set;
	int			found_no;
	int			found_so;
	int			found_we;
	int			found_ea;
	int			i;
	t_map		*map;
	t_player	*player;
	t_img		*img;
}				t_mlx;

int			close_and_free(t_mlx *mlx);
void		init_image(t_mlx *mlx);
void		pixel_put(t_img *img, double x, double y, int color);
void		draw_map2d(t_map *map, t_img *img, t_player *player);
void		draw_player2d(t_mlx *mlx, t_player *player);
t_player	*init_player(t_player *player);
void		draw_line(t_point begin, t_point end, t_img *img, int color);
void		read_texture(char *path, t_map *cub);
void		read_color(char *path, t_map *cub, t_mlx *var);
void		read_map(char *path, t_map *cub);
void		len_map(t_map *cub);
void		insert_space_map(t_map *cub);
void		validation_map(char *av, t_map *map, t_mlx *mlx);
void		error(char *error);
void		insert_space_map(t_map *cub);
void		process_map(t_map *cub);
char		*adjust_line_length(char *line, size_t max_len);
void		process_color_line(char *line, t_map *cub, t_mlx *var);
void		count(t_map *cub, int width, int heigth);
void		check_cub(char *map);
void		file_validation(t_map *cub, t_mlx *var);
void		validation_color_f(t_map *cub);
void		validation_color_c(t_map *cub);
void		validate_map_all(t_map *cub);
int			horizontal_map(t_map *cub);
int			vertical_map(t_map *cub);
void		caracter_valid(t_map *cub);
void 		free_mat(char **mat);
void		clear_screen(t_img *img);

#endif
