/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:31:54 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/03 21:19:11 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H 
# define FT_HEADER_H 

# include <stdlib.h> 
# include <stdio.h> 
# include <unistd.h>
# include <stdlib.h>

void	free_storage(char **storage);
char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *storage, char *buffer);
size_t	ft_strlen(char *s);


#endif