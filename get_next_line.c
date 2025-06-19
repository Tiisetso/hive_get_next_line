/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/19 12:43:18 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //TODO: remove

//Read one line from a file or stdin
//If error or nothing or read, return NULL.
//Return line should include \n EXCEPT when EOF is reached and has no \n

//Has anything been stored?
//If yes, prepend new reads
//If no, add to here
//Read into buffer
//Has newline been found
//If yes, everything up until newline is returned. Extra is stored.
//If no, everything is stored, read again.
char *get_next_line(int fd)
{
	char *line;
	static char buf[BUFFER_SIZE];
	int length;
	int i;

	length = ft_strlen(buf);
	if (length = 0) //nothing stored
	{
		read(fd, buf, BUFFER_SIZE);
		i = 0;
		//Find \n
		//If found extract line and store remainder
		
		while (buf[i] || i < BUFFER_SIZE)
		{

		}
	}
	else //something stored
	{

	}
	
	//Line malloc to be size of stored + new
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