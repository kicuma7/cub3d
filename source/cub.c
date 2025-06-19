/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:55:39 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 19:56:12 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
void	tmp_map(t_map *map, const char *filename);

int	init(t_map *map, t_cub *cub)
{
	cub->img2d = malloc(sizeof(t_img));
	cub->con = mlx_init();
	cub->win3d = mlx_new_window(cub->con, SCREEN_WID, SCREEN_HEI, "CUB 3D");
	cub->win2d = mlx_new_window(cub->con, map->wid * TILE, map->hei * TILE, \
								"Mini Map");
	cub->img2d->img = mlx_new_image(cub->con, map->wid * TILE, map->hei * TILE);
	cub->img2d->img_addr = (int *)mlx_get_data_addr(cub->img2d->img, &(int){0}, \
							&cub->img2d->size_line, &(int){0});
	cub->player = malloc(sizeof(t_player));
	init_player(cub->player, map->map);
	draw_2d_game(cub);
	mlx_put_image_to_window(cub->con, cub->win2d, cub->img2d->img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.map = malloc(sizeof(t_map));
	if (ac <= 1)
		return (0);
	tmp_map(cub.map, av[1]);
	init(cub.map, &cub);
	mlx_loop(cub.con);
}



/* #################  REMOVE THIS BEFORE FINISH ALL ###################### */

#define MAX_LINE_LEN 1024
# include <string.h>

void	tmp_map(t_map *map, const char *filename)
{
	FILE	*file;
	char	buffer[MAX_LINE_LEN];
	size_t	lines_alloc = 10;
	size_t	line_count = 0;
	size_t	max_width = 0;

	map->map = malloc(sizeof(char *) * lines_alloc);
	if (!map->map)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (!file)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, MAX_LINE_LEN, file))
	{
		size_t	len;

		// remove newline se houver
		len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		len = strlen(buffer); // recalcula depois de remover o \n

		if (line_count >= lines_alloc)
		{
			lines_alloc *= 2;
			map->map = realloc(map->map, sizeof(char *) * lines_alloc);
			if (!map->map)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		map->map[line_count] = strdup(buffer);
		if (!map->map[line_count])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		if (len > max_width)
			max_width = len;
		line_count++;
	}
	map->hei = line_count;
	map->wid = max_width;
	fclose(file);
}
/* #################  REMOVE THIS BEFORE FINISH ALL ###################### */
