/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:45:05 by timurray          #+#    #+#             */
/*   Updated: 2025/06/19 15:08:37 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count))
		count++;
	return (count);
}
//Build the string of previously read line + buffer
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	size_t	s_size;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	s_size = s1_length + s2_length + 1;
	s = (char *)malloc((s_size) * sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, s1_length);
	ft_memcpy(s + s1_length, s2, s2_length);
	s[s_size - 1] = '\0';
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	temp_dest = dest;
	temp_src = (const unsigned char *)src;
	while (n > 0)
	{
		*temp_dest++ = *temp_src++;
		n--;
	}
	return (dest);
}
//Find '\n'
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0' && *s == (const char)c)
		return ((char *)s);
	return (NULL);
}