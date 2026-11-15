/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkyawh <hkyawh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:16:27 by hkyawh            #+#    #+#             */
/*   Updated: 2026/11/12 23:15:49 by hkyawh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i;
    
    i=0;
    if (!s)
    	return (0);
    while (s[i])
        i++;
    return(i);
}

char	*str_join(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *result;
    
    i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

int find_newline(const char *s)
{
    size_t i;
    
    i = 0;
    if(!s)
        return(-1);
    while(s[i])
    {
        if(s[i] == '\n')
            return(i);
        i++;
    }
    return(-1);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*s_str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	s_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_str)
		return (NULL);
	while (i < len)
	{
		s_str[i] = s[start + i];
		i++;
	}
	s_str[len] = '\0';
	return (s_str);
}
