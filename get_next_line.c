/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:30:44 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/07 20:15:12 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>


char    *get_next_line(int fd)
{
    static char	*storage;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    return (return_line(&storage, fd)); 
}

char    *return_line(char **storage, int fd)
{
    char    *pt_to_nl;
    char    *line;

    pt_to_nl = find_nl(storage, fd); 
    if (!*storage || !pt_to_nl)
        return (NULL);
    line = ft_strndup(*storage, (pt_to_nl - *storage) + 1);
    
    // ATENÇÃO: Depois de pegar a linha, você PRECISA atualizar a storage 
    // para limpar o que já foi lido, senão o loop vai ler sempre a mesma linha!
    // ex: *storage = limpar_storage_antiga(*storage);

    return (line);
}

char    *find_nl(char **storage, int fd)
{
    char        buffer[BUFFER_SIZE + 1];
    char        *pt_to_nl;
	char		*temp;
    int         read_bytes;

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
        free_storage(storage);
        *storage = temp;
	}
    return (ft_strchr(*storage, '\n'));
}
