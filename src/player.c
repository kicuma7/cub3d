/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:02:33 by user              #+#    #+#             */
/*   Updated: 2025/06/04 22:55:34 by user             ###   ########.fr       */
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
