/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/03 20:44:39 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub.h"

void	validation_map(char *path, t_map *cub, t_mlx *var)
{
	check_cub(path);
	read_map(path, cub);
	read_color(path, cub, var);
	read_texture(path, cub);
	validate_map_all(cub);
	file_validation(cub, var);
	validation_color_c(cub);
}

void	validate_map_all(t_map *cub)
{
	if (horizontal_map(cub) != 1 || vertical_map(cub) != 1)
		error("\033[31mvertical map error and horizontal\033[0m");
	caracter_valid(cub);
}

int	horizontal_map(t_map *cub)
{
	int	j;

	if (!cub->map || cub->hei < 2 || cub->wid < 1)
		error("\033[31mInvalid map dimensions\033[0m");
	j = 0;
	while (j < cub->wid)
	{
		if (cub->map[0][j] == '0' || cub->map[cub->hei - 1][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

int	vertical_map(t_map *cub)
{
	int	j;
	int	i;

	if (!cub->map || cub->hei < 1 || cub->wid < 1)
		error("\033[31mInvalid map dimensions\033[0m");
	j = 0;
	while (j < cub->hei)
	{
		i = 0;
		while (i < cub->wid)
		{
			if (i > 0 && cub->map[j][i] == ' ' && cub->map[j][i - 1] == '0')
				return (0);
			if (i > 0 && cub->map[j][i - 1] == ' ' && cub->map[j][i] == '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	caracter_valid(t_map *cub)
{
	int	heigth;
	int	witdth;

	heigth = 0;
	witdth = 0;
	while (heigth < cub->hei)
	{
		witdth = 0;
		while (witdth < cub->wid)
		{
			if (cub->map[heigth][witdth] != ' '
				&& cub->map[heigth][witdth] != '\n')
				count(cub, witdth, heigth);
			witdth++;
		}
		heigth++;
	}
}
