/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:04:27 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/02 12:17:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	free_map(t_map *map)
{
	size_t	i;

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
	mlx_destroy_window(mlx->con, mlx->win);
	#ifdef __linux__
		mlx_destroy_display(mlx);
	#endif
	//mlx_destroy_display(mlx->con);
	free(mlx->con);
	exit(EXIT_SUCCESS);
	return (0);
}
