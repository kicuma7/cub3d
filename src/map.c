/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:36:42 by jquicuma          #+#    #+#             */
/*   Updated: 2025/04/22 11:17:12 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*static void	put_map_to_screen(char **map, t_img *img)
{

}*/

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
	static bool	map_is_builded = false;
	int			fd;
	int			i;

	if (!map_is_builded)
	{
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
	}
	//put_map_to_screen(mlx->map);
	return (0);
}
