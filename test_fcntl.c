/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fcntl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:13:43 by marferre          #+#    #+#             */
/*   Updated: 2022/10/03 23:14:04 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd;
	char buff[10];
	ssize_t	nbt;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		printf("error\n");
	else
	{
		nbt = read(fd, buff, 5);
		close(fd);
		if (!nbt)
			printf("vacío\n");
		else
			printf("characters: %d, content: %s \n", (int)nbt, buff);
	}
	return (0);
}
