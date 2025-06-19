/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:20:39 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/01 09:53:29 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr_fd("salut\n", 1);
// 	return (0);
// }
