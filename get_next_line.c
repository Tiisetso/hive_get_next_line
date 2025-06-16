/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:44:43 by timurray          #+#    #+#             */
/*   Updated: 2025/06/16 12:50:50 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Read one line from a file or stdin
//If error or nothing or read, return NULL.
//Return line should include \n EXCEPT when EOF is reached and has no \n
char *get_next_line(int fd)
{
	char *line;


	return (line);
}


#include <fcntl.h>
int main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if(fd != -1)
	{
		
	}
	printf("\nfd = %i\n", fd);
	printf("%i", BUFFER_SIZE);
	return (1);
}