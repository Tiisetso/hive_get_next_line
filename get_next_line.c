/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/23 12:58:45 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //TODO: remove

/* Requirements
Read one line from a file or stdin
If error or nothing or read, return NULL.
Return line should include \n EXCEPT when EOF is reached and has no \n

Store a string that has at least one '\n'.
Read line until '\n' is found
If readline already has a '\n' return it
If readline doesn't have '\n' read and append buffer. Check again. */
char *ft_read_line(char *read_line, int fd)
{
	int count;
	// char buf[BUFFER_SIZE + 1];
	char *temp;

	char *buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if(!buf)
		return (NULL);

	count = 0;
	if (!read_line)
	{
		read_line = (char *)malloc(1);
		if (!read_line)
			return (NULL);
		read_line[0] = '\0';
	}
	// while (ft_strchr(read_line, '\n') == NULL)
	// {
	// 	count = read(fd, buf, BUFFER_SIZE);
	// 	if (count == 0)
	// 	{	
	// 		return (NULL);
	// 	}
	// 	buf[count] = '\0';
	// 	read_line = ft_strjoin(read_line, buf);
	// }
	while (!ft_strchr(read_line, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
			break;
		buf[count] = '\0';
		temp = ft_strjoin(read_line, buf);
		if (!temp)
		{
			free(read_line);
			return (NULL);
		}
		free(read_line);
		read_line = temp;
	}
	free(buf);
	return (read_line);
}

int	newline_index(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return (i);
		i++;
	}
	return (i);
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

//Stores the fully read
char *get_next_line(int fd)
{
	static char *read_line;
	char *line;
	int n_index;
	int length;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	read_line = ft_read_line(read_line, fd);
	if (!read_line || *read_line == '\0')
	{
		free(read_line);
		read_line = NULL;
		return (NULL);
	}
	// printf("\nBuffer read line:\n%s", read_line);

	n_index = newline_index(read_line, '\n');
	// printf("\nnewline index: %i\n", n_index);

	line = ft_substr(read_line, 0, n_index +1);
	// printf("\nExtracted line:\n%s", line);
	if (!line)
		return (NULL);

	length = (ft_strlen(read_line) - n_index);
	// read_line = ft_substr(read_line, n_index + 1, length);
	// printf("\n\nRemaining line:\n%s", read_line);

	temp = ft_substr(read_line, n_index + 1, length - 1);
	free(read_line);
	read_line = temp;
	return (line);
}


