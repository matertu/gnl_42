/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:31:54 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/05 19:55:50 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	free_storage(char **storage);
char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *storage, char *buffer);
char	*find_nl(char **storage, int fd);
char	*return_line(char **storage);
size_t	ft_strlen(char *s);

#endif