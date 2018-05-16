#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer[50];
	char temp[50];
	int fd;
	int wcount,rcount;
	int pos;

	fd = open("./test2.txt",O_RDWR);
	sprintf(buffer, "Do Not Count The Before They Hatch!!");
	wcount = write(fd, buffer, strlen(buffer)+1);
	printf("파일에 쓴 문자열 개수 : %d\n",wcount);
	

	pos=lseek(fd,0,SEEK_SET);
	// 이거 안써두면 읽어온 문자열의 개수에 1이 들어간다.
	// 그리고 읽어온 문자열에도 제대로 출력되지 않는다.

	rcount = read(fd, temp, strlen(buffer)+1);
	printf("읽어온 문자열 개수 : %d\n",rcount);
	printf("문자열 : %s\n", temp);
	
	close(fd);
	return 0;
}
