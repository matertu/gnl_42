/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:30:44 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/08 18:47:39 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_storage(char **storage)
{
	if (storage && *storage)
	{
		free(*storage);
		*storage = NULL;
	}
}

char	*return_line(char **storage)
{
	char	*pt_to_nl;
	char	*line;
	char	*temp;

	if (!storage || !*storage || **storage == '\0')
	{
		free_storage(storage);
		return (NULL);
	}
	pt_to_nl = ft_strchr(*storage, '\n');
	if (pt_to_nl)
	{
		line = ft_strndup(*storage, (pt_to_nl - *storage) + 1);
		temp = NULL;
		if (*(pt_to_nl + 1) != '\0')
			temp = ft_strdup(pt_to_nl + 1);
		free_storage(storage);
		*storage = temp;
	}
	else
	{
		line = ft_strdup(*storage);
		free_storage(storage);
	}
	return (line);
}

char	*find_nl(char **storage, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		read_bytes;

	if (!*storage)
		*storage = ft_strdup("");
	if (!*storage)
		return (NULL);
	read_bytes = 1;
	while (!(ft_strchr(*storage, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free_storage(storage);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(*storage, buffer);
		*storage = temp;
	}
	return (*storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!find_nl(&storage, fd))
		return (NULL);
	return (return_line(&storage));
}
