/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/02 12:52:12 by user             ###   ########.fr       */
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
	t_mlx	mlx;
	t_map	map;

	//LINHA PARA APLICAR A VALIDACAO TODA DO MAPA
	if (ac < 2)
		return (0);
	tmp_map(&map, av[1]); // LINHA TEMPORARIA PARA SUBSTITUIR COM A VALIDACAO
	for (int i = 0; map.map[i]; i++)
		printf("%s\n", map.map[i]);
	//TRAZER TAMBEM TODOS OS DADOS NECESSARIOS DO MAPA DENTRO DA ESTRUTURA T_MAP

	mlx.map = &map;
	mlx.con = mlx_init();
	init_image(&mlx);
	mlx.win = mlx_new_window(mlx.con, map.pixels_wid, map.pixels_hei, "CUB3D");
	mlx_hook(mlx.win, 17, 0, &close_and_free, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, &pressed_key, &mlx);
	mlx_loop(mlx.con);
}
