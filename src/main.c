/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:50:49 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 12:48:13 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		mlx_hook(mlx.win, 17, 0, &mlx_destroy_all, &mlx);
		mlx_loop(mlx.con);
	}
	return (0);
}
