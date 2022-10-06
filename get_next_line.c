/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:19:52 by marferre          #+#    #+#             */
/*   Updated: 2022/10/06 18:40:06 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save_file(char const *gl, int fd)
{
	int		file;
	char	*ln_f;
	
	ln_f = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ln_f)
		return (0);
	if ((!(ft_strchr(gl, '\n'))))
	{
		file = read(fd, ln_f, BUFFER_SIZE);
		if (file <= 0)
		{
			free(ln_f);
			return (0);
		}
	}
	return (ln_f);
}

char	*get_next_line(int fd)
{
	static char	*ln;
	char		*gl;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	ln = ft_save_file(gl, fd);
	return (ln);
}
