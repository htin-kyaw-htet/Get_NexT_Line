/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkyawh <hkyawh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:18:44 by hkyawh            #+#    #+#             */
/*   Updated: 2026/11/12 22:28:05 by hkyawh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef    BUFFER_SIZE
#  define   BUFFER_SIZE 42
# endif

size_t  ft_strlen(const char *s);
char	*str_join(char *s1, char *s2);
int find_newline(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *get_next_line(int fd);

#endif