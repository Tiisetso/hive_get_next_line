/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:45:05 by timurray          #+#    #+#             */
/*   Updated: 2025/06/18 12:07:54 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while ((*s1 || *s2) && (i < n))
	{
		result = *s1++ - *s2++;
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}