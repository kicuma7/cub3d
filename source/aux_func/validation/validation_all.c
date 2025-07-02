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

void	count(t_map *cub, int width, int heigth)
{
	int		player_count;
	char	c;

	c = cub->map[heigth][width];
	player_count = 0;
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ' && c != '\n')
	{
		printf("\033[31mError caractere invalid\033[0m %c", c);
		exit(1);
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		player_count++;
	}
	if (player_count > 1)
		error("\033[31mError with player\033[0m");
}

void	process_color_line(char *line, t_map *cub, t_mlx *var)
{
	if (line[0] != '\0' && line[0] != ' ')
	{
		if (line[0] == 'F')
		{
			cub->color[0] = ft_strdup(line);
			var->floor_set++;
		}
		else if (line[0] == 'C')
		{
			cub->color[1] = ft_strdup(line);
			var->ceiling_set++;
		}
	}
}

char	*adjust_line_length(char *line, size_t max_len)
{
	size_t	len;
	char	*new_line;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len >= max_len)
		return (line);
	new_line = malloc(max_len + 2);
	if (!new_line)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(new_line, line, len);
	ft_memset(new_line + len, ' ', max_len - len);
	new_line[max_len] = '\n';
	new_line[max_len + 1] = '\0';
	free(line);
	return (new_line);
}

void	process_map(t_map *cub)
{
	len_map(cub);
	insert_space_map(cub);
}

void	error(char *error)
{
	printf("%s", error);
	exit(0);
}
