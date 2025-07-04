/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:20:39 by jquicuma          #+#    #+#             */
/*   Updated: 2025/07/02 12:32:31 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_point_int	set_side_dist(t_point *side_dist, t_point player_pos,\
				t_point_int map_point, t_point delta_dist, t_point ray_dir)
{
	t_point_int	step;

	if (ray_dir.x < 0)
	{
		step.x = -1;
		(*side_dist).x = (player_pos.x / TILE - map_point.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		(*side_dist).x = (map_point.x + 1.0 - player_pos.x / TILE) * delta_dist.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		(*side_dist).y = (player_pos.y / TILE - map_point.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		(*side_dist).y = (map_point.y + 1.0 - player_pos.y / TILE) * delta_dist.y;
	}
	return (step);
}

t_hit_info	ray_loop(char **map, t_point_int map_point, t_point_int step,
				t_point delta_dist, t_point side_dist)
{
	t_hit_info	hit_info;

	hit_info.hit = 0;
	while (hit_info.hit == 0)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map_point.x += step.x;
			hit_info.side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map_point.y += step.y;
			hit_info.side = 1;
		}
		if (map[map_point.y][map_point.x] == '1')
			hit_info.hit = 1;
	}
	if (hit_info.side == 0)
		hit_info.perp_wall_dist = (side_dist.x - delta_dist.x);
	else
		hit_info.perp_wall_dist = (side_dist.y - delta_dist.y);
	return (hit_info);
}

t_hit_info	get_ray_colision(t_point player_pos, t_point ray_dir, char **map)
{
	t_point_int	step;
	t_point_int	map_point;
	t_point		delta_dist;
	t_point		side_dist;
	t_hit_info	hit_info;

	hit_info.hit = 0;
	if (ray_dir.x == 0)
		delta_dist.x = 1e30;
	else
		delta_dist.x = fabs(1.0 / ray_dir.x);
	if (ray_dir.y == 0)
		delta_dist.y = 1e30;
	else
		delta_dist.y = fabs(1.0 / ray_dir.y);
	map_point.x = (int)(player_pos.x / TILE);
	map_point.y = (int)(player_pos.y / TILE);
	step = set_side_dist(&side_dist, player_pos, map_point, delta_dist, ray_dir);
	hit_info = ray_loop(map, map_point, step, delta_dist, side_dist);
	hit_info.point.x = player_pos.x + (hit_info.perp_wall_dist * ray_dir.x * TILE);
	hit_info.point.y = player_pos.y + (hit_info.perp_wall_dist * ray_dir.y * TILE);
	hit_info.perp_wall_dist *= TILE;
	return (hit_info);
}

void	ray_launcher(t_player *player, char **map, t_img *img2d, t_img *img3d)
{
	int			i;
	t_point		ray_dir;
	float		ray_angle;
	float		increment;
	t_hit_info	hit_info;

	ray_angle = player->dir_angle - (FOV / 2);
	increment = FOV / SCREEN_WID;
	i = 0;
	draw_floor_and_ceil(img3d);
	while (i < SCREEN_WID)
	{
		ray_dir.x = cos(ray_angle + (270 * (PI / 180)));
		ray_dir.y = sin(ray_angle + (270 * (PI / 180)));
		hit_info = get_ray_colision(player->position, ray_dir, map);
		hit_info.perp_wall_dist = hit_info.perp_wall_dist * cos(player->dir_angle - ray_angle);
		draw_line(player->position, hit_info.point, img2d, 0xffe6e6);
		draw_wall(hit_info, i, img3d);
		ray_angle += increment;
		i++;
	}
}
