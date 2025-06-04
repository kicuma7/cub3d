/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/04 22:49:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	pressed_key(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		close_and_free(mlx);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || \
			keycode == RIGHT)
	{
		mov_player_position(mlx->player, keycode);
	}
	else if (keycode == ROTATE_LEFT)
		mlx->player->dir_angle -= PI / 32;
	else if (keycode == ROTATE_RIGHT)
		mlx->player->dir_angle += PI / 32;
	update_frame(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_map		map;
	t_img		img;
	t_player	player;

	if (ac <= 1)
		return (0);
	mlx.con = mlx_init();
	init(&mlx, &map, &img, &player, av[1]);
	t_dimension dim;
	t_point		pos;
	dim.wid = 20;
	dim.hei = 20;
	pos.x = 0;
	pos.y = 0;
	draw_map(&map, &img);
	draw_player(&player, &img);
	mlx_put_image_to_window(mlx.con, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, ON_DESTROY, 0, &close_and_free, &mlx);
	mlx_hook(mlx.win, ON_KEYDOWN, 1L<<0, &pressed_key, &mlx);
	mlx_loop(mlx.con);
	return (0);
}
