/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/22 15:57:18 by timurray         ###   ########.fr       */
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
	char buf[BUFFER_SIZE + 1];

	count = 0;
	if (!read_line)
	{
		read_line = (char *)malloc(1);
		if (!read_line)
			return (NULL);
		read_line[0] = '\0';
	}
	while (ft_strchr(read_line, '\n') == NULL)
	{
		count = read(fd, buf, BUFFER_SIZE);
		// printf("\n--count--\n%i", count);
		if (count == 0)
		{	
			return (NULL);
		}
		buf[count] = '\0';
		read_line = ft_strjoin(read_line, buf);
	}
	return (read_line);
}

//Stores the fully read
char *get_next_line(int fd)
{
	static char *read_line;
	char *line;
	int n_index;
	int length;

	read_line = ft_read_line(read_line, fd);
	if (read_line == NULL)
		return (NULL);
	// printf("\nBuffer read line:\n%s", read_line);

	n_index = newline_index(read_line, '\n');
	// printf("\nnewline index: %i\n", n_index);

	line = ft_substr(read_line, 0, n_index +1);
	// printf("\nExtracted line:\n%s", line);

	length = (ft_strlen(read_line) - n_index);
	read_line = ft_substr(read_line, n_index + 1, length);
	// printf("\n\nRemaining line:\n%s", read_line);
	return (line);
}

#include <fcntl.h> //TODO: remove
int main(void)
{
	int fd;
	char *line;


	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("No file found");
	}
	else
	{
		line = get_next_line(fd);
		printf("%s", line);
		while (line)
		{
			line = get_next_line(fd);
			printf("%s", line);
		}
	}
	close(fd);
	return (1);
}
