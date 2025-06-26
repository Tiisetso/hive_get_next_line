/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:43:32 by timurray          #+#    #+#             */
/*   Updated: 2025/06/25 10:16:16 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	//fd = open("100_paragraphs.txt", O_RDONLY);
	// fd = open("big.txt", O_RDONLY);
	// fd = open("empty.txt", O_RDONLY);
	// fd = open("no_file.txt", O_RDONLY);
	// fd = open("mixed.txt", O_RDONLY);
	// fd = open("long_line.txt", O_RDONLY);
	// fd = open("bible.txt", O_RDONLY);
	// fd = 0; //stdin
	if (fd == -1)
		printf("No file found");
	else
	{
		while ((line = get_next_line(fd)))
		{
			printf("line %i: %s", i, line);
			i++;
			free(line);
		}
		printf("%s", line);
		
	}
	close(fd);
	return (1);
}
