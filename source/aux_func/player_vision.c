/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_vision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:52:20 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/29 12:05:19 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	draw_camera_vision_line(t_player *player, t_img *img)
{
	t_point	dir;
	t_point	final_line_point;
	t_point	plane;
	int		line_size;

	line_size = 40;
	dir.y = sin(angulo);
	dir.x = cos(angulo);
	plane.x = -dir.y * FOV;
	plane.y = dir.x * FOV;
	final_line_point.x = player->center.x + (cos(player->dir_angle + (PI / 2)) * line_size);
	final_line_point.y = player->center.y - (sin(player->dir_angle + (PI / 2)) * line_size);
	draw_line(player->center, final_line_point, img, 0xFF00FF);
	final_line_point.x = player->center.x + (cos(player->dir_angle - (PI / 2)) * line_size);
	final_line_point.y = player->center.y - (sin(player->dir_angle - (PI / 2)) * line_size);
	draw_line(player->center, final_line_point, img, 0xFF00FF);
}
