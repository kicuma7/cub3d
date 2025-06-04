/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:03:04 by user              #+#    #+#             */
/*   Updated: 2025/06/04 01:11:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	draw_player(t_player *player, t_img *img)
{
	t_dimension	player_dimension;

	player_dimension.wid = PIXELS / 4;
	player_dimension.hei = PIXELS / 4;
	draw_square(img, player_dimension, player->position, 0xff00ff);
}
