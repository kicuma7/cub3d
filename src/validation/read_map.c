/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:03 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/06 09:37:57 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	read_texture(char *path, t_map *cub)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	cub->texture = malloc(sizeof(char *) * 5);
	while (line != NULL)
	{
		if (line[0] != '\0' && line[0] != ' ' && (line[0] == 'N'
				|| line[0] == 'S' || line[0] == 'W' || line[0] == 'E'))
		{
			if (i >= 4)
				error("\033[31mError File\033[0m");
			cub->texture[i] = ft_strdup(line);
			if (!cub->texture[i])
				error("\033[31mError File\033[0m");
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	cub->texture[i] = NULL;
	close(fd);
}

void	read_color(char *path, t_map *cub, t_mlx *var)
{
	char	*line;
	int		fd;

	var->floor_set = 0;
	var->ceiling_set = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("\033[31mError File\033[0m");
	line = get_next_line(fd);
	cub->color = malloc(sizeof(char *) * 3);
	while (line != NULL)
	{
		process_color_line(line, cub, var);
		free(line);
		line = get_next_line(fd);
	}
	if (var->floor_set > 1 || var->ceiling_set > 1)
		error("\033[31m repeated characters \033[0m");
	if (!cub->color[0] || !cub->color[1])
		error("\033[31mError: Missing color definition\033[0m");
	cub->color[2] = NULL;
	close(fd);
}

void	read_map(char *path, t_map *cub)
{
	int		fd;
	int		i;
	char	*line;
	int		map_started;

	i = 0;
	map_started = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("\033[31mError File\033[0m");
	line = get_next_line(fd);
	cub->map = malloc(sizeof(char *) * 100);
	while (line != NULL)
	{
		if (map_started || (line[0] == ' ' || line[0] == '1'))
		{
			map_started = 1;
			cub->map[i++] = ft_strdup(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	cub->map[i] = NULL;
	process_map(cub);
	close(fd);
}

void	len_map(t_map *cub)
{
	int	i;

	cub->max_len = 0;
	i = 0;
	while (cub->map[i] != NULL)
	{
		if (ft_strlen(cub->map[i]) > cub->max_len)
			cub->max_len = ft_strlen(cub->map[i]);
		i++;
	}
	cub->hei = i;
	cub->wid = cub->max_len;
	cub->pixels_wid = cub->wid * PIXELS;
	cub->pixels_hei = cub->hei * PIXELS;
}

void	insert_space_map(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map[i] != NULL)
	{
		cub->map[i] = adjust_line_length(cub->map[i], cub->max_len);
		i++;
	}
}
