/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:50:49 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/23 11:32:11 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pressed_key(int key_code, t_mlx *mlx)
{
	if (key_code == ESC)
		mlx_destroy_all(mlx);
	else if (key_code == UP)
		mlx->player_pos_hei -= MOV;
	else if (key_code == DOWN)
		mlx->player_pos_hei += MOV;
	else if (key_code == RIGHT)
		mlx->player_pos_wid += MOV;
	else if (key_code == LEFT)
		mlx->player_pos_wid -= MOV;
	printf("P WID %f | P HEI %f\n", mlx->player_pos_wid, mlx->player_pos_hei);
	clear_screen(mlx->img, mlx->map_wid * PIXELS, mlx->map_hei * PIXELS);
	put_map_to_screen(mlx->map, mlx->img, mlx);
	put_player_on_screen(mlx->player_pos_wid, mlx->player_pos_hei, mlx, \
						mlx->img);
	printf("%d\n", key_code);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;

	if (ac > 1)
	{
		mlx.con = mlx_init();
		mlx.img = &img;
		build_map(&mlx, av[1]);
		mlx.win = mlx_new_window(mlx.con, mlx.map_wid * PIXELS, \
					mlx.map_hei * PIXELS, "cub3D");
		put_map_to_screen(mlx.map, mlx.img, &mlx);
		put_player_on_screen(mlx.player_pos_wid, \
							mlx.player_pos_hei, &mlx, &img);
		mlx_hook(mlx.win, 2, 1L << 0, &pressed_key, &mlx);
		mlx_hook(mlx.win, 17, 0, &mlx_destroy_all, &mlx);
		mlx_loop(mlx.con);
	}
	return (0);
}
