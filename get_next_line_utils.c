/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:34:38 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/07 19:30:51 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_storage(char **storage)
{
	free(*storage);
	*storage = NULL;
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (storage);		
	new_str = malloc(sizeof(char) * (ft_strlen(storage) + ft_strlen(buffer) + 1));
	if (!new_str)
	{
		free_storage(&storage);
		return (NULL);
	}
	i = 0;
	if (*storage)
	{
		while (storage[i])
		{
			new_str[i] = storage[i];
			i++;
		}
	}
	j = 0;
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	if (storage)
		free_storage(&storage);
	return (new_str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	len = 0;
	while (s[len] && len < n)
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}
