/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:21:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/29 13:36:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	destroy_mlx_elements(t_cub *cub)
{
	if (cub->img3d->img != NULL)
		mlx_destroy_image(cub->con, cub->img3d->img);
	if (cub->img2d->img != NULL)
		mlx_destroy_image(cub->con, cub->img2d->img);
	if (cub->win2d != NULL)
		mlx_destroy_window(cub->con, cub->win2d);
	if (cub->win3d != NULL)
		mlx_destroy_window(cub->con, cub->win3d);
	/*Descomentar essa Linha quando for mecher no Linux HEADER COM USER*/
	//mlx_destroy_display(cub->con);
	free(cub->con);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_and_free(t_cub *cub)
{
	destroy_mlx_elements(cub);
	if (cub->img2d != NULL)
		free(cub->img2d);
	if (cub->img3d != NULL)
		free(cub->img3d);
	if (cub->map != NULL)
	{
		free_map(cub->map->map);
		free(cub->map);
	}
	if (cub->player != NULL)
		free(cub->player);
	exit(0);
	return (0);
}
