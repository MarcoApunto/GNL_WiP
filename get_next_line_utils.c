/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:19:54 by marferre          #+#    #+#             */
/*   Updated: 2022/10/03 23:19:54 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Lo usaré para medir buffer && para strchr*/
size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Me han recomendado usarlo*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1 || !s2)
		return (0);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i++ < ft_strlen(s1))
		dst[i] = s1[i];
	j = 0;
	while (j++ < ft_strlen(s2))
		dst[i++] = s2[j];
	dst[i] = '\0';
	return (dst);
}

/*Lo usaré para encontrar el '\n'*/
char	*ft_strchr(char const *str, int c)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(str))
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
