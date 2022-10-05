#include <fcntl.h>
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
