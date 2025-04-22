/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:35:02 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 11:18:41 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# define ERROR_CODE -1
# define PIXELS 20

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct	s_img
{
	int		size_line;
	void	*img;
	int		*img_addr;
}			t_img;

typedef struct	s_mlx
{
	int		map_wid;
	int		map_hei;
	void	*con;
	void	*win;
	char	**map;
	t_img	*img;
}				t_mlx;

int		mlx_destroy_all(t_mlx *mlx);
int		build_map(t_mlx *mlx, char *mapfilename);
void	init_image(t_img *img, size_t wid, size_t hei, t_mlx *mlx);

#endif
