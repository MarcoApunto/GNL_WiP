/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fcntl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:13:43 by marferre          #+#    #+#             */
/*   Updated: 2022/10/04 09:29:16 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char buff[30];
	int	nbt;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		printf("error\n");
	else
	{
		nbt = read(fd, buff, 30);
		
		close(fd);
		
		if (!nbt)
			printf("empty")
		else
			while (!(ft_strchr(buff, '\n')))
				write(1, buff, 1);
	}
	return (0);
}