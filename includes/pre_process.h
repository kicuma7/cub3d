/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:23:15 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/21 14:58:56 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_PROC
# define PRE_PROC

# define SPEED 5
# define SCREEN_WID 640
# define SCREEN_HEI 400
# define TILE 25
# define PI 3.14159265359

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define ROTATE_L 65361
# define ROTATE_R 65363
# define LEFT 97
# define RIGHT 100
# define FOV (66 * (PI / 180))

# define ON_KEYPRESS 02

# define ABS(n) ((n >= 0) ? n : (n * (-1)))

#endif
