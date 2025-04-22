/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:36:42 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 12:36:33 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	fill_square(t_img *img, int wid, int hei, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PIXELS)
	{
		j = 0;
		while (j < PIXELS)
		{
			pixel_put(img, wid + i, hei + j, color);
			j++;
		}
		i++;
	}
}

void	put_map_to_screen(char **map, t_img *img, t_mlx *mlx)
{
	int	hei;
	int	wid;

	hei = 0;
	while (map[hei])
	{
		wid = 0;
		while (map[hei][wid])
		{
			if (map[hei][wid] == '1')
				fill_square(img, wid * PIXELS, hei * PIXELS, MAP_COLOR);
			wid++;
		}
		hei++;
	}
	mlx_put_image_to_window(mlx->con, mlx->win, img->img, 0, 0);
}

static int	get_map_hei(char *mapfilename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(mapfilename, O_RDONLY);
	if (fd == -1)
		return (ERROR_CODE);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	free(line);
	return (height);
}

int	build_map(t_mlx *mlx, char *mapfilename)
{
	int			fd;
	int			i;

	mlx->map_hei = get_map_hei(mapfilename);
	fd = open(mapfilename, O_RDONLY);
	if (fd == -1)
		return (ERROR_CODE);
	mlx->map = (char **)malloc(sizeof(char *) * ((mlx->map_hei) + 1));
	i = 0;
	mlx->map_wid = 0;
	mlx->map[i] = get_next_line(fd);
	while (mlx->map[i])
	{
		if (ft_strlen(mlx->map[i]) > (size_t)mlx->map_wid)
			mlx->map_wid = ft_strlen(mlx->map[i]) - 1;
		i++;
		mlx->map[i] = get_next_line(fd);
	}
	init_image(mlx->img, mlx->map_wid * PIXELS, mlx->map_hei * PIXELS, mlx);
	return (0);
}
