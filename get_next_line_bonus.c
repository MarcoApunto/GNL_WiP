/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:38:14 by marferre          #+#    #+#             */
/*   Updated: 2022/10/12 11:08:15 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_control_leaks(char *gl)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (gl[i] && gl[i] != '\n')
		i++;
	if (!gl[i])
	{
		free(gl);
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(gl) - i) + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (gl[i])
		str[j++] = gl[i++];
	str[j] = '\0';
	free(gl);
	return (str);
}

static char	*ft_line(char *gl)
{
	int		i;
	char	*str;

	i = 0;
	if (!gl[i])
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
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_save_file(char *gl, int fd)
{
	int		file;
	char	*fl_sv;

	fl_sv = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!fl_sv)
		return (NULL);
	file = 1;
	while (!ft_strchr(gl, '\n') && file != 0)
	{
		file = read(fd, fl_sv, BUFFER_SIZE);
		if (file == -1)
		{
			free(fl_sv);
			return (NULL);
		}
		fl_sv[file] = '\0';
		gl = ft_strjoin(gl, fl_sv);
	}
	free(fl_sv);
	return (gl);
}

char	*get_next_line(int fd)
{
	static char	*gl[OPEN_MAX];
	char		*ln;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(gl[fd]);
		gl[fd] = NULL;
		return (NULL);
	}
	gl[fd] = ft_save_file(gl[fd], fd);
	if (!gl[fd])
		return (NULL);
	ln = ft_line(gl[fd]);
	gl[fd] = ft_control_leaks(gl[fd]);
	return (ln);
}
