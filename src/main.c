/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/26 10:56:30 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void		tmp_map(t_map *map, const char *filename);

/*
static void	draw_fov(t_player *player, t_img *img, int screen_resolution)
{
	double	begin_angle;
	double	end_angle;
	double	iterator;

	begin_angle = player->dir_angle - (PI / 6);
	end_angle = player->dir_angle + (PI / 6);
	iterator = (end_angle - begin_angle) / screen_resolution;
	int	i = 0;
	while (begin_angle < end_angle)
	{
		draw_line_acording_angle(player, img, begin_angle, 200);
		begin_angle += iterator;
		i++;
	}
}
*/

static int	pressed_key(int keycode, t_mlx *mlx)
{
	double	left_right_angle;


	left_right_angle = mlx->player->dir_angle + (PI / 2);
	if (keycode == ESC)
		close_and_free(mlx);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT \
			|| keycode == RIGHT)
			mov_player(mlx->player, keycode, left_right_angle);
	else if (keycode == ROT_LEFT)
		mlx->player->dir_angle += PI / 32;
	else if (keycode == ROT_RIGHT)
		mlx->player->dir_angle -= PI / 32;
	clear_screen(mlx->img);
	draw_player2d(mlx, mlx->player);
	//draw_fov(mlx->player, mlx->img, 1920);
	draw_map2d(mlx->map, mlx->img, mlx->player);
	mlx_put_image_to_window(mlx->con, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;

	if (ac < 2)
		return (0);
	validation_map(av[1], &map, &mlx);
	mlx.map = &map;
	mlx.con = mlx_init();
	init_image(&mlx);
	mlx.win = mlx_new_window(mlx.con, map.pixels_wid, map.pixels_hei, "CUB3D");
	draw_map2d(mlx.map, mlx.img, &player);
	mlx.player = init_player(&player);
	draw_player2d(&mlx, &player);
	pixel_put(mlx.img, (int)player.center.x, (int)player.center.y, 0xFF0000);
	mlx_put_image_to_window(mlx.con, mlx.win, mlx.img->img, 0, 0);
	mlx_hook(mlx.win, 17, 0, &close_and_free, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &pressed_key, &mlx);
	mlx_loop(mlx.con);
}
