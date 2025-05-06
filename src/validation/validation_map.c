/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/01 12:19:18 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub.h"

void	check_cub(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (!(map[i - 1] == 'b' && map[i - 2] == 'u'))
		error("\033[31mError with extension\033[0m");
	if (!(map[i - 3] == 'c' && map[i - 4] == '.'))
		error("\033[31mError with extension\033[0m");
}

void	file_validation(t_map *cub, t_mlx *var)
{
	var->i = 0;
	var->found_no = 0;
	var->found_so = 0;
	var->found_we = 0;
	var->found_ea = 0;
	while (cub->texture[var->i] != NULL)
	{
		if (ft_strncmp(cub->texture[var->i], "NO ", 3) == 0)
			var->found_no++;
		if (ft_strncmp(cub->texture[var->i], "SO ", 3) == 0)
			var->found_so++;
		if (ft_strncmp(cub->texture[var->i], "WE ", 3) == 0)
			var->found_we++;
		if (ft_strncmp(cub->texture[var->i], "EA ", 3) == 0)
			var->found_ea++;
		var->i++;
	}
	if (var->found_ea > 1 || var->found_no > 1 || var->found_so > 1
		|| var->found_we > 1)
		error("\033[31mDuplicate identifiers\033[0m");
	if (var->found_ea != 1 || var->found_no != 1 || var->found_so != 1
		|| var->found_we != 1)
		error("\033[31mMissing identifiers\033[0m");
}

void	validation_color(t_map *cub)
{
	char	*c;
	char	*f;
	char	**rest_c;
	char	**rest_f;
	int		i;

	if (cub->color[0][0] == 'F')
		f = cub->color[0] + 2;
	if (cub->color[1][0] == 'C')
		c = cub->color[1] + 2;
	rest_f = ft_split(f, ',');
	rest_c = ft_split(c, ',');
	i = 0;
	while (rest_c[i] != NULL)
	{
		if (ft_atoi(rest_c[i]) > 255 || ft_atoi(rest_c[i]) < 0)
			error("\033[31minvalid color \033[0m");
		free(rest_c[i]);
		i++;
	}
	if (i > 3)
		error("\033[31minvalid color \033[0m");
	i = 0;
	while (rest_f[i] != NULL)
	{
		if (ft_atoi(rest_f[i]) > 255 || ft_atoi(rest_f[i]) < 0)
			error("\033[31minvalid color \033[0m");
		free(rest_f[i]);
		i++;
	}
	if (i > 3)
		error("\033[31minvalid color \033[0m");
	free(rest_c);
	free(rest_f);
}
