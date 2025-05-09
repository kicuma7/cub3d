/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:56:32 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/09 10:05:54 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# define PI 3.14159265359

int	main(int ac, char **av)
{
	double angulo = 0;
	int	speed = 1;
	double	pos_x = 4;
	double	pos_y = 7;
	double	right_left_angle;

	printf("%f\n%f\n\n\n", cos(angulo), sin(angulo));
	double coseno_x = speed * cos(angulo);
	double seno_y = speed * sin(angulo);
	printf("CIMA\n");
	printf("SENO: %f\nCOSENO: %f\n", pos_x + coseno_x, pos_y - seno_y);
	printf("BAIXO\n");
	printf("SENO: %f\nCOSENO: %f\n", pos_x - coseno_x, pos_y + seno_y);
	printf("ESQUERDA\n");
	right_left_angle = angulo + (PI / 2);
	coseno_x = speed * cos(right_left_angle);
	seno_y = speed * sin(right_left_angle);
	printf("SENO: %f\nCOSENO: %f\n", pos_x + coseno_x, pos_y - seno_y);
	printf("DIREITA\n");
	printf("SENO: %f\nCOSENO: %f\n", pos_x - coseno_x, pos_y + seno_y);
	return (0);
}
