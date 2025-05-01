/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:26:01 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/01 10:00:33 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*len_total(int fd, char *buffer)
{
	char	*str;
	int		size;

	str = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size = 1;
	while (!ft_strchr_gnl(buffer, '\n') && (size != 0))
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
		{
			free(str);
			return (NULL);
		}
		str[size] = '\0';
		buffer = ft_strjoin_gnl(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*len_return(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *) malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*len_rest(char	*buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *) malloc((ft_strlen_gnl(buffer) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer_str;
	char		*len_tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer_str = len_total(fd, buffer_str);
	if (!buffer_str)
		return (NULL);
	len_tmp = len_return(buffer_str);
	buffer_str = len_rest(buffer_str);
	return (len_tmp);
}
