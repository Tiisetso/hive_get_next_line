/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/16 15:53:13 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //TODO: remove

//Read one line from a file or stdin
//If error or nothing or read, return NULL.
//Return line should include \n EXCEPT when EOF is reached and has no \n
char *get_next_line(int fd)
{
	char *line;
	ssize_t	count;
	void *buf[BUFFER_SIZE];

	count = 0;
	count = read(fd, buf, BUFFER_SIZE);
	printf("char read: %zi\n", count);
	printf("read: %s", (char *)buf);

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
	}
	
	printf("\n\n%i", BUFFER_SIZE);
	return (1);
}