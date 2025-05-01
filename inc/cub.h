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

#ifndef CUB_H
# define CUB_H

# include "../libs/libft/inc/libft.h"
# include "../libs/mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define PIXELS 20
# define ESC 65307

typedef struct	s_map
{
	char		**map;
	size_t		hei;
	size_t		wid;
	size_t		pixels_wid;
	size_t		pixels_hei;
}				t_map;

typedef struct	s_mlx
{
	void		*con;
	void		*win;
	t_map		*map;
}				t_mlx;

int		close_and_free(t_mlx *mlx);

#endif
