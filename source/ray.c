/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:20:39 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/22 19:44:57 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_point	check_horizontal_colision(t_point initial_pos, float ray_angle, char **map)
{
	t_point	first_inter;
	t_point	delta;
}

t_point	ray_caster(t_point ray_initial_pos, t_point ray_dir, char **map)
{
	int		x;
	int		y;
	t_point	final_ray_pos;

	final_ray_pos = ray_initial_pos;
	while (true)
	{
		final_ray_pos.x += ray_dir.x;
		final_ray_pos.y += ray_dir.y;
		x = (int)(final_ray_pos.x / TILE);
		y = (int)(final_ray_pos.y / TILE);
		if (map[y][x] == '1')
			break ;
	}
	return (final_ray_pos);
}

void	ray_launcher(t_player *player, char **map, t_img *img)
{
	t_point	ray_dir;
	float	norm_angle;
	float	ray_angle;
	float	increment;
	t_point	angle_final_position;

	ray_angle = player->dir_angle - (FOV / 2);
	increment = FOV / SCREEN_WID;
	int	i = 0;
	while (ray_angle < (player->dir_angle + (FOV/ 2)))
	{
		norm_angle = normalize_angle(ray_angle);
		ray_dir.x = cos(norm_angle + (270 * (PI / 180)));
		ray_dir.y = sin(norm_angle + (270 * (PI / 180)));
		(void)img;
		angle_final_position = ray_caster(player->position, ray_dir, map);
		draw_line(player->position, angle_final_position, img, 0xffe6e6);
		ray_angle += increment;
		i++;
	}
}
