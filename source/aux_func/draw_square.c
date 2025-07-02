/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:source/aux_func/draw_square.c
/*   Created: 2025/06/19 17:49:29 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 17:55:59 by jquicuma         ###   ########.fr       */
=======
/*   Created: 2025/05/01 12:04:27 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/06 08:55:07 by jquicuma         ###   ########.fr       */
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a:src/free.c
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_square(t_img *img, int size, t_point pos, int color)
{
<<<<<<< HEAD:source/aux_func/draw_square.c
	int		i;
	int		j;
	t_point	pixel_pos;
=======
	int	i;
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a:src/free.c

	i = 0;
<<<<<<< HEAD:source/aux_func/draw_square.c
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_pos.x = pos.x + i;
			pixel_pos.y = pos.y + j;
			pixel_put(img, pixel_pos, color);
			j++;
		}
		i++;
	}
=======
	while (i < map->hei)
		free(map->map[i++]);
	free(map->map);
	map->map = NULL;
}

int	close_and_free(t_mlx *mlx)
{
	free_map(mlx->map);
	free_mat(mlx->map->texture);
	free_mat(mlx->map->color);
	mlx_destroy_window(mlx->con, mlx->win);
	mlx_destroy_image(mlx->con, mlx->img->img);
	#ifdef __linux__
		mlx_destroy_display(mlx->con);
	#endif
	free(mlx->con);
	free(mlx->img);
	exit(EXIT_SUCCESS);
	return (0);
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a:src/free.c
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	if (mat == NULL || *mat == NULL)
		return ;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
