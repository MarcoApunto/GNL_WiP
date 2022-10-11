/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:39:03 by marferre          #+#    #+#             */
/*   Updated: 2022/10/11 17:39:12 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (0);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strdup(char const *src)
{
	int		i;
	int		len;
	char	*dst;

	len = ft_strlen(src);
	dst = malloc (sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(char const *str, int c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
