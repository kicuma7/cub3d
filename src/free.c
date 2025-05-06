/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:04:27 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/01 12:11:34 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->map)
		return ;
	i = 0;
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
	mlx_destroy_display(mlx->con);
	free(mlx->con);
	exit(EXIT_SUCCESS);
	return (0);
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
