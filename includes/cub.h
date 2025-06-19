/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:55:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/19 12:23:33 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "pre_process.h"
# include "../library/libft/inc/libft.h"
# include "../library/mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct	s_cub
{
	void	*con;
	void	*win2d;
	void	*win3d;
}				t_cub;

#endif
