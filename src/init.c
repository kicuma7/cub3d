/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:03:07 by user              #+#    #+#             */
/*   Updated: 2025/06/16 19:30:53 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
void	tmp_map(t_map *map, const char *filename);

static void	init_img(t_img *img, t_mlx *mlx)
{
	img->img = mlx_new_image(mlx->con, SCREEN_WID, SCREEN_HEI);
	img->img_addr = (int *)mlx_get_data_addr(img->img, &img->bpp, \
					&img->size_line, &(int){0});
	mlx->img = img;
}

static void	set_player_dir_angle(t_player *player, char cardinal_point)
{
	if (cardinal_point == 'N')
		player->dir_angle = 0;
	else if (cardinal_point == 'S')
		player->dir_angle = PI;
	else if (cardinal_point == 'E')
		player->dir_angle = PI / 2;
	else if (cardinal_point == 'W')
		player->dir_angle = PI + (PI / 2);
}

static void	init_player(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'|| \
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				player->position.x = j * PIXELS;
				player->position.y = i * PIXELS;
				set_player_dir_angle(player, map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	init(t_mlx *mlx, t_map *map, t_img *img, t_player *player, char *filename)
{
	tmp_map(map, filename);
	init_img(img, mlx);
	mlx->win = mlx_new_window(mlx->con, SCREEN_WID, SCREEN_HEI, "CUB3D");
	init_player(player, map->map);
	mlx->player = player;
	mlx->map = map;
}
