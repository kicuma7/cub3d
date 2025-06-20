/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:18:22 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/20 14:47:17 by jquicuma         ###   ########.fr       */
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

void	move_player(t_player *player, int keycode)
{
	float	left_right_angle;

	left_right_angle = player->dir_angle + (PI / 2);
	if (keycode == UP)
	{
		player->position.x += sin(player->dir_angle) * SPEED;
		player->position.y -= cos(player->dir_angle) * SPEED;
	}
	else if (keycode == DOWN)
	{
		player->position.x -= sin(player->dir_angle) * SPEED;
		player->position.y += cos(player->dir_angle) * SPEED;
	}
	else if (keycode == LEFT)
	{
		player->position.x -= sin(left_right_angle) * SPEED;
		player->position.y += cos(left_right_angle) * SPEED;
	}
	else if (keycode == RIGHT)
	{
		player->position.x += sin(left_right_angle) * SPEED;
		player->position.y -= cos(left_right_angle) * SPEED;
	}
	else if (keycode == ROTATE_L || keycode == ROTATE_R)
		rotate_player(player, keycode);
}
