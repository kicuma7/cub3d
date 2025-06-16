/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_pocess.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:48:55 by user              #+#    #+#             */
/*   Updated: 2025/06/16 17:22:38 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_POCESS_H
# define PRE_POCESS_H

#ifndef ABS
# define ABS(n) ((n > 0) ? n : (n * (-1)))
#endif

# ifndef EVENTS_H
#  define EVENTS_H
#  define ON_KEYDOWN 2
#  define ON_DESTROY 17
# endif

# ifndef KEYS_H
#  define KEYS_H
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
#  define ROTATE_LEFT 97
#  define ROTATE_RIGHT 100
# endif

# ifndef SCREEN_ELEMENTS_H
#  define SCREEN_ELEMENTS_H
#  define SCREEN_WID 640
#  define SCREEN_HEI 480
#  define PIXELS 20
#  define PI 3.14159265358979323846
#  define MOV_VELOCITY 5
# endif

#endif
