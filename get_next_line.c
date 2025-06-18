/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/18 16:47:52 by timurray         ###   ########.fr       */
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
	ssize_t	count;
	char buf[BUFFER_SIZE + 1];
	int i;
	int newline_found;
	char temp[100];

	count = 0;
	newline_found = 0;
	while (buf[i])
	{
		buf[i++] = 0;
	};

	i = 0;

	newline_found = 0;
	while ((newline_found == 0) && (count = read(fd, buf, 1)))
	{
	}

	printf("\n\n------------------------\nchar read: %zi", count);

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
		printf("\nfd = %i\n", fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
	}
	
	printf("\nBUFFER SIZE: %i", BUFFER_SIZE);
	return (1);
}