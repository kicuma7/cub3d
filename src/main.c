/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/27 09:49:20 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static t_point	draw_each_fov_line(t_point main_line, double angle, t_map *map)
{
	t_point	final_line;
	int		x;
	int		y;

	final_line = main_line;
	while (true)
	{
		final_line.x += 1 * cos(angle);
		final_line.y -= 1 * sin(angle);
		x = (int)(final_line.x / PIXELS);
		y = (int)(final_line.y / PIXELS);
		if (x == map->wid || y == map->hei || map->map[y][x] == '1'\
			|| x <= 0 || y <= 0)
			break ;
	}
	return (final_line);
}

void	draw_fov(t_mlx *mlx, double init_angle)
{
	t_point	final_line;
	double	final_angle;
	double	increment;

	final_angle = init_angle + FOV;
	increment = FOV / SCREEN_WID;
	while (init_angle < final_angle)
	{
		final_line = draw_each_fov_line(mlx->player->center, \
					init_angle, mlx->map);
		draw_line(mlx->player->center, final_line, mlx->img, 0xFF0000);
		init_angle += increment;
	}
}

static int	pressed_key(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		close_and_free(mlx);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT \
			|| keycode == RIGHT)
			mov_player(mlx->player, keycode);
	else if (keycode == ROT_LEFT)
		mlx->player->dir_angle += PI / 32;
	else if (keycode == ROT_RIGHT)
		mlx->player->dir_angle -= PI / 32;
	clear_screen(mlx->img);
	draw_fov(mlx, mlx->player->dir_angle - (FOV / 2));
	draw_player2d(mlx, mlx->player);
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
