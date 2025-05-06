/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/06 08:28:27 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	tmp_map(t_map *map, const char *filename);

static int	pressed_key(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		close_and_free(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;

	//LINHA PARA APLICAR A VALIDACAO TODA DO MAPA
	//if (ac < 2)
	//	return (0);
	(void)ac;
	(void)av;
	//tmp_map(&map, "/Users/user/dev/cub3d/assets/maps/map.cub");
	tmp_map(&map, "/home/jquicuma/dev/cub3d/assets/maps/map.cub");
	// LINHA TEMPORARIA PARA SUBSTITUIR COM A VALIDACAO
	//TRAZER TAMBEM TODOS OS DADOS NECESSARIOS DO MAPA DENTRO DA ESTRUTURA T_MAP

	mlx.map = &map;
	mlx.con = mlx_init();
	init_image(&mlx);
	mlx.win = mlx_new_window(mlx.con, map.pixels_wid, map.pixels_hei, "CUB3D");
	draw_map2d(mlx.map, mlx.img, &player);
	mlx.player = init_player(&player);
	draw_player2d(&mlx, &player);
	pixel_put(mlx.img, (int)player.center.x, (int)player.center.y, 0xFF0000);
	printf("X: %f\nY: %f\n", player.center.x, player.center.y);
	printf("X: %f\nY: %f\n", player.point_a.x, player.point_a.y);
	mlx_put_image_to_window(mlx.con, mlx.win, mlx.img->img, 0, 0);
	mlx_hook(mlx.win, 17, 0, &close_and_free, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, &pressed_key, &mlx);
	mlx_loop(mlx.con);
}
