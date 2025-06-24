/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:44:44 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/22 19:49:11 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

float	normalize_angle(float angle)
{
	angle = fmod(angle, (2 * PI));
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

bool	is_facing_down(float angle)
{
	return (angle > (PI * 0.5) && angle < (PI * 1.5));
}

bool	is_facing_right(float angle)
{
	return (angle < PI && angle > 0);
}
