/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:56:54 by user              #+#    #+#             */
/*   Updated: 2025/06/03 23:16:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_img
{
	void	*img;
	int		*img_addr;
	int		size_line;
	int		bpp;
}			t_img;

typedef struct	s_dimension
{
	size_t		wid;
	size_t		hei;
}				t_dimension;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_map
{
	char		**map;
}				t_map;

typedef struct	s_mlx
{
	void		*con;
	void		*win;
	t_map		*map;
	t_img		*img;
}				t_mlx;

#endif
