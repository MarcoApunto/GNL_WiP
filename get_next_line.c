/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:19:52 by marferre          #+#    #+#             */
/*   Updated: 2022/10/08 19:46:55 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save_file(char *ln, int fd)
{
	int		file;
	char	*fl_sv;
	
	fl_sv = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!fl_sv)
		return (0);
	if (!ft_strchr(fl_sv, '\n'))
	{
		file = read(fd, fl_sv, BUFFER_SIZE);
		if (file <= 0)
		{
			free(fl_sv);
			return (0);
		}
		fl_sv[file] = '\0';
		if (!ln)
			ln = ft_strdup(fl_sv);
		else
			ln = ft_strjoin(ln, fl_sv);
	}
	free(fl_sv);
	return (ln);
}

char	*get_next_line(int fd)
{
	static char	*ln;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	ln = ft_save_file(ln, fd);
	return (ln);
}
