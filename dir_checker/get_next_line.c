/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:41:11 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/08 12:04:34 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_write_left(char *string)
{
	int		i;
	char	*dest;

	i = 0;
	while (string && string[i] && string[i] != '\n')
		i++;
	if (string && string[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (string && string[i])
	{
		dest[i] = string[i];
		if (dest[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_write_right(char *temp)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (temp && temp[i] && temp[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen_gnl(temp) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (temp && temp[i])
	{
		i++;
		dest[j] = temp[i];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_read_buffer(int fd, char *buffer, char *string)
{
	char	*temp;
	int		size;

	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buffer[size] = '\0';
		temp = string;
		string = ft_strjoin_gnl(temp, buffer);
		free(temp);
		if ((ft_strchr_gnl(string, '\n')))
			break ;
	}
	return (string);
}

int	ft_free_gnl(char *buffer, char *temp, char *string, char *sentence)
{
	free(temp);
	free(buffer);
	if (*sentence == '\0')
	{
		free(sentence);
		free(string);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*string;
	char		*temp;
	char		*sentence;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	string = ft_read_buffer(fd, buffer, string);
	sentence = ft_write_left(string);
	temp = string;
	string = ft_write_right(temp);
	if (ft_free_gnl(buffer, temp, string, sentence))
	{
		string = NULL;
		return (NULL);
	}
	free(string);
	string = NULL;
	return (sentence);
}
