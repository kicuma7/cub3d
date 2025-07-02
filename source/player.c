/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:18:22 by jquicuma          #+#    #+#             */
/*   Updated: 2025/07/02 12:26:39 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	rotate_player(t_player *player, int keycode)
{
	if (keycode == ROTATE_R)
	{
		if ((player->dir_angle + (PI / 32)) > (PI * 2))
			player->dir_angle = (player->dir_angle + (PI / 32)) - (PI * 2);
		else
			player->dir_angle += PI / 32;
	}
	else if (keycode == ROTATE_L)
	{
		if ((player->dir_angle - (PI / 32)) < 0)
		{
			player->dir_angle -= (PI / 32);
			player->dir_angle += (PI * 2);
		}
		else
			player->dir_angle -= PI / 32;
	}
}

static void	set_player_pos_and_direction(t_player *player, \
				char cardinal_point, int x, int y)
{
	player->position.x = x * TILE;
	player->position.y = y * TILE;
	if (cardinal_point == 'N')
		player->dir_angle = 0;
	else if (cardinal_point == 'S')
		player->dir_angle = PI;
	else if (cardinal_point =='E')
		player->dir_angle = 90 * (PI / 180);
	else if (cardinal_point == 'W')
		player->dir_angle = 270 * (PI / 180);
}
void	init_player(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
				set_player_pos_and_direction(player, map[i][j], j, i);
			j++;
		}
		i++;
	}
}

static void	move_up_down(t_player *player, int keycode, char **map, \
						t_point_int map_pos)
{
	if (keycode == UP)
	{
		player->position.x += sin(player->dir_angle) * SPEED;
		player->position.y -= cos(player->dir_angle) * SPEED;
		map_pos.x = (int)(player->position.x / TILE);
		map_pos.y = (int)(player->position.y / TILE);
		if (map[map_pos.y][map_pos.x] == '1')
		{
			player->position.x -= sin(player->dir_angle) * SPEED;
			player->position.y += cos(player->dir_angle) * SPEED;
		}
	}
	else if (keycode == DOWN)
	{
		player->position.x -= sin(player->dir_angle) * SPEED;
		player->position.y += cos(player->dir_angle) * SPEED;
		map_pos.x = (int)(player->position.x / TILE);
		map_pos.y = (int)(player->position.y / TILE);
		if (map[map_pos.y][map_pos.x] == '1')
		{
			player->position.x += sin(player->dir_angle) * SPEED;
			player->position.y -= cos(player->dir_angle) * SPEED;
		}
	}
}

static void	move_left_right(t_player *player, int keycode, char **map, \
						t_point_int map_pos, float angle)
{
	if (keycode == LEFT)
	{
		player->position.x -= sin(angle) * SPEED;
		player->position.y += cos(angle) * SPEED;
		map_pos.x = (int)(player->position.x / TILE);
		map_pos.y = (int)(player->position.y / TILE);
		if (map[map_pos.y][map_pos.x] == '1')
		{
			player->position.x += sin(angle) * SPEED;
			player->position.y -= cos(angle) * SPEED;
		}
	}
	else if (keycode == RIGHT)
	{
		player->position.x += sin(angle) * SPEED;
		player->position.y -= cos(angle) * SPEED;
		map_pos.x = (int)(player->position.x / TILE);
		map_pos.y = (int)(player->position.y / TILE);
		if (map[map_pos.y][map_pos.x] == '1')
		{
			player->position.x -= sin(angle) * SPEED;
			player->position.y += cos(angle) * SPEED;
		}
	}
}

void	move_player(t_player *player, int keycode, char **map)
{
	t_point_int	map_pos;
	float		left_right_angle;

	left_right_angle = player->dir_angle + (PI / 2);
	map_pos.x = 0;
	map_pos.y = 0;
	if (keycode == UP || keycode == DOWN)
		move_up_down(player, keycode, map, map_pos);
	else if (keycode == LEFT || keycode == RIGHT)
		move_left_right(player, keycode, map, map_pos, left_right_angle);
	else if (keycode == ROTATE_L || keycode == ROTATE_R)
		rotate_player(player, keycode);
}
