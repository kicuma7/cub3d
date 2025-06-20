/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:55:39 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/20 10:17:14 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
void	tmp_validate(t_map *map, const char *filename);

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.map = malloc(sizeof(t_map));
	cub.map->map = NULL;
	if (ac <= 1)
		return (0);
	tmp_validate(cub.map, av[1]);
	init(cub.map, &cub);
	mlx_hook(cub.win2d, 17, 0, &close_and_free, &cub);
	mlx_loop(cub.con);
}



/* #################  REMOVE THIS BEFORE FINISH ALL ###################### */

#define MAX_LINE_LEN 1024
# include <string.h>

void	tmp_validate(t_map *map, const char *filename)
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
		if (line_count < lines_alloc)
	{
		map->map[line_count] = NULL;
    }
	else
	{
		// Se a alocação atual é exatamente a quantidade de linhas,
		// precisamos de mais espaço para o NULL terminator.
		map->map = realloc(map->map, sizeof(char *) * (line_count + 1));
		if (!map->map)
		{
			perror("realloc for NULL terminator");
			exit(EXIT_FAILURE);
		}
		map->map[line_count] = NULL;
	}
	map->hei = line_count;
	map->wid = max_width;
	fclose(file);
}
/* #################  REMOVE THIS BEFORE FINISH ALL ###################### */
