/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:55:39 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 12:09:32 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_cub	mlx;

	(void)ac;
	(void)av;
	mlx.con = mlx_init();
	mlx.win2d = mlx_new_window(mlx.con, SCREEN_WID, SCREEN_HEI, "Mini Map");
	mlx_loop(mlx.con);
}
