/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/01 12:20:22 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void		tmp_map(t_map *map, const char *filename);

static int	pressed_key(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		close_and_free(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;

	// LINHA PARA APLICAR A VALIDACAO TODA DO MAPA
	if (ac < 2)
		return (0);
	validation_map(av[1], &map, &mlx);
	mlx.map = &map;
	mlx.con = mlx_init();
	mlx.win = mlx_new_window(mlx.con, 500, 500, "CUB3D");
	mlx_hook(mlx.win, 17, 0, &close_and_free, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &pressed_key, &mlx);
	mlx_loop(mlx.con);
}
