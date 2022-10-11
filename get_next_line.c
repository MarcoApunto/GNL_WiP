/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:19:52 by marferre          #+#    #+#             */
/*   Updated: 2022/10/11 16:04:07 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_line(char *gl)
{
	int		i;
	char	*str;

	i = 0;
	if (!gl)
		return (NULL);
	while (gl[i] && gl[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (gl[i] && gl[i] != '\n')
	{
		str[i] = gl[i];
		i++;
	}
	if (gl[i] == '\n')
	{
		str[i] = gl[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_save_file(char *gl, int fd)
{
	int		file;
	char	*fl_sv;

	if (!gl)
		gl = malloc(sizeof(char));
	fl_sv = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!fl_sv)
		return (NULL);
	file = 1;
	while (file != 0)
	{
		file = read(fd, fl_sv, BUFFER_SIZE);
		if (file == -1)
		{
			free(fl_sv);
			return (NULL);
		}
		fl_sv[file] = '\0';
		gl = ft_strjoin(gl, fl_sv);
		printf("%s", gl);
		if (ft_strchr(gl, '\n'))
			break ;
	}
	
	free(fl_sv);
	return (gl);
}

char	*get_next_line(int fd)
{
	static char	*gl;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	gl = ft_save_file(gl, fd);
	if (!gl)
		return (NULL);
	printf("%s", gl);
	ln = ft_line(gl);
	return (ln);
}
