#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>

void leaks()
{
	system("leaks a.out");
}

int main(){
	int fd= open("file.txt", O_RDONLY);
	//int fd2= open("file2.txt", O_RDONLY);

	char * a = get_next_line(fd);
	//char *b = get_next_line(fd2);
	while(a){
		printf("%s", a);
		a = get_next_line(fd);
	}
	free(a);
	//free(b);
	close(fd);
	//atexit(leaks);
	return 0;
}
