/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:45:26 by timurray          #+#    #+#             */
/*   Updated: 2025/06/18 12:08:33 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

char *get_next_line(int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif