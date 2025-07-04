/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:16:12 by jquicuma          #+#    #+#             */
/*   Updated: 2025/07/02 12:57:24 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	init(t_map *map, t_cub *cub)
{
	cub->img2d = malloc(sizeof(t_img));
	cub->img3d = malloc(sizeof(t_img));
	cub->con = mlx_init();
	cub->win3d = mlx_new_window(cub->con, SCREEN_WID, SCREEN_HEI, "CUB 3D");
	cub->img3d->img = mlx_new_image(cub->con, SCREEN_WID, SCREEN_HEI);
	cub->img3d->img_addr = (int *)mlx_get_data_addr(cub->img3d->img, &(int){0}, \
							&cub->img3d->size_line, &(int){0});
	cub->img2d->img = mlx_new_image(cub->con, map->wid * TILE, map->hei * TILE);
	cub->img2d->img_addr = (int *)mlx_get_data_addr(cub->img2d->img, &(int){0}, \
							&cub->img2d->size_line, &(int){0});
	cub->player = malloc(sizeof(t_player));
	init_player(cub->player, map->map);
	draw_3d_game(cub);
	draw_2d_game(cub);
	return (1);
}
