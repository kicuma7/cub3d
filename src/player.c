/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:02:33 by user              #+#    #+#             */
/*   Updated: 2025/06/04 23:21:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	mov_player_position(t_player *player, int keycode)
{
	float	left_right_angle;

	left_right_angle = player->dir_angle + (PI / 2);
	if (keycode == UP)
	{
		player->position.x += sin(player->dir_angle) * MOV_VELOCITY;
		player->position.y -= cos(player->dir_angle) * MOV_VELOCITY;
	}
	else if (keycode == DOWN)
	{
		player->position.x -= sin(player->dir_angle) * MOV_VELOCITY;
		player->position.y += cos(player->dir_angle) * MOV_VELOCITY;
	}
	else if (keycode == LEFT)
	{
		player->position.x -= sin(left_right_angle) * MOV_VELOCITY;
		player->position.y += cos(left_right_angle) * MOV_VELOCITY;
	}
	else if (keycode == RIGHT)
	{
		player->position.x += sin(left_right_angle) * MOV_VELOCITY;
		player->position.y -= cos(left_right_angle) * MOV_VELOCITY;
	}
}

void	rotate_player(t_player *player, int keycode)
{
	if (keycode == ROTATE_RIGHT)
	{
		if ((player->dir_angle + (PI / 32)) > (PI * 2))
			player->dir_angle = (player->dir_angle + (PI / 32)) - (PI * 2);
		else
			player->dir_angle += PI / 32;
	}
	else if (keycode == ROTATE_LEFT)
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
