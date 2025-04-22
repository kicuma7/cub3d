/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:50:49 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 11:14:22 by jquicuma         ###   ########.fr       */
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
		build_map(&mlx, av[1]);
		mlx.win = mlx_new_window(mlx.con, mlx.map_wid * PIXELS, \
					mlx.map_hei * PIXELS, "cub3D");
		init_image(&img, mlx.map_wid * PIXELS, mlx.map_hei * PIXELS, &mlx);
		mlx_hook(mlx.win, 17, 0, &mlx_destroy_all, &mlx);
		mlx_loop(mlx.con);
	}
	return (0);
}
