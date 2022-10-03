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

/*Me han recomendado usar, se necesita tunear*/
char	*ft_strjoin(char *dst, char const *src);

/*Lo usaré para encontrar el '\n'*/
char	*ft_strchr(char const *str, int c)
{
	int i;

	i = 0;
	while ((size_t)i < ft_strlen(str))
	{
		if (str[i] == (char)c)
			return((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}