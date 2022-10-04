/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:19:52 by marferre          #+#    #+#             */
/*   Updated: 2022/10/04 10:17:11 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char()

char	*get_next_line(int fd)
{
	static char	*fd;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
}
