#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define RBUFSIZE 10

int main(void)
{
	int fd; // file discripter의 약자
	char temp[10];
	char rbuf[10];
	int wcount;
	int rcount;
	int pos;
	fd=open("./test.txt",O_RDWR|O_CREAT|O_TRUNC,  
		S_IXUSR|S_IWUSR|S_IRUSR|S_IWGRP|S_IRGRP|S_IROTH);

	// WRONLY : WRITE ONLY로 하나 열자
	// CREAT : 없으면 하나 생성하자
	// TRUNC : 파일이 존재하면 지워버리고 공백으로 만들어주자
	// 		(기존파일 무시)
	// S_IWUSR : 유저의 권한은 Write
	// S_IRUSR : 유저의 권한은 Read
	// S_IRGRP : 그룹의 권한은 Read
	// S_IROTH : Others의 권한은 READ
	// S_IRWXU로 하면 IXUSR IWUSR IRUSR 기능 합친거
	// but, 그렇게 해도 초록색파일 (실행파일)이 되지는 않는다.
	// open은 기존의 파일을 갖고 읽고쓰기때문!!
	// 권한 제대로 부여해서 실행파일 만들려면 creat를 사용하자

	if(fd==-1) {   // 파일오픈에 실수했을 경우
	printf("file open error!!\n");
	return -1;
	}
	
	sprintf(temp,"TEST!!\n"); // temp에 "TEST!!"를 넣는다. 
	write(1,temp,strlen(temp)); //파일 디스크립터가 1번은 stdout
	// printf를 포함하지 않고 printf기능을 했으며
	// 파일디스크립터 1번이 stdout임을 확인하였다.

	//text.txt파일에 문자열 쓰기
	wcount = write(fd, "경찰청창살쇠창살\n",20);
	//파일에 쓴 문자열 갯수 출력
	printf("wcount = %d\n",wcount);

	close(fd);                         //
	


	fd = open("./test.txt",O_RDONLY);  // 이거 두줄 안넣으면 rbuf=@나옴
					   // 아니면 주석처리하고
	
	 				   // pos = lseek(fd,0,SEEK_SET);
					   // 파일내의 커서 위치를
					   // 시작점 기준으로 offset 0번지로
					   // 이동	(항상 양수)
					   //

	//lseek(fd, offset, SEEK_END); 끝점기준으로 offset (항상음수)
	//lseek(fd, offset, SEEK_CUR); 현재커서 기준으로 offset (양수음수)

	// 파일을 읽어서 rbuf배열에 채움
	rcount = read(fd,rbuf,RBUFSIZE);
	// 읽은 문자열 갯수를 확인
	printf("rcount = %d\n",rcount);
	// 읽은 버퍼의 내용을 확인
	printf("rbuf = %s\n", rbuf);

	printf("fd=%d\n",fd);
	// fd를 printf하면 3이 나온다. 0번은 stdin 1번은 stdout 2번은 stderr

	close(fd);
	
	fd = creat("./test2.txt",0764); // user에 rwx, group에 rw-, other r
	if(fd==-1)
	{
		printf("file open error!!\n");
		return -1;
	}
	
	printf("creat의 fd = %d\n",fd); // 마찬가지로 3출력
	return 0;

}
