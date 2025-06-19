/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/19 15:12:36 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //TODO: remove

//Requirements
//Read one line from a file or stdin
//If error or nothing or read, return NULL.
//Return line should include \n EXCEPT when EOF is reached and has no \n

//Store a string that has at least one '\n'.
//Read line until '\n' is found
//If readline already has a '\n' return it
//If readline doesn't have '\n' read and append buffer. Check again.
char *ft_read_line(char *read_line, int fd)
{
	int count;

	count = 0;

	return (read_line);
}
//Get the first line from the stored readline.
char *ft_new_line(char *read_line)
{
	char *new_line;

	return (new_line);
}

//Stores the fully read
char *get_next_line(int fd)
{
	static char *read_line;
	char *line;
	read_line = ft_read_line(read_line, fd);

	return (line);
}

#include <fcntl.h> //TODO: remove
int main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("No file found");
	}
	else
	{
		get_next_line(fd);
	}
	
	printf("\nBUFFER SIZE: %i", BUFFER_SIZE);
	return (1);
}