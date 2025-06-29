/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:23:15 by jquicuma          #+#    #+#             */
/*   Updated: 2025/06/29 13:41:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_PROC
# define PRE_PROC

# define SPEED 5
# define SCREEN_WID 640
# define SCREEN_HEI 400
# define TILE 25
# define PI 3.14159265359

/*
Descomentar essas linhas no Linux

Nao esquecer de verificar todos os cabecalhos para certificar que esta correto

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define ROTATE_L 65361
# define ROTATE_R 65363
# define LEFT 97
# define RIGHT 100
# define FOV (66 * (PI / 180))
*/

# ifndef KEYS_H
#  define KEYS_H
#  define ESC 53
#  define LEFT 0
#  define RIGHT 2
#  define UP 126
#  define DOWN 125
#  define ROTATE_L 123
#  define ROTATE_R 124
# define FOV (66 * (PI / 180))
# endif

# define ON_KEYPRESS 02

# define ABS(n) ((n >= 0) ? n : (n * (-1)))

#endif
