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

	char * a = get_next_line(fd);printf("%s", a);
	
	//char *b = get_next_line(fd2);
	//while(a){
		
		//printf("%s", b);
	//	a = get_next_line(fd);
		//b = get_next_line(fd2);

	//}
	free(a);
	//free(b);
	close(fd);
	//atexit(leaks);
	return 0;
}
