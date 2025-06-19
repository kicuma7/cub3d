/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:18:22 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 19:47:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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
