#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>	// 파일 입출력을 위한 헤더
#include <unistd.h>	// fcnt1(),open()을 위한 자료형,상수 그리고 함수 정의
#include <stdio.h>	

#define BUFFSIZE 1024

int main(int argc, char **argv)	//argc : cmd창에서 받는 인자의 갯수
				//argv[] : 실행시 cmd창에서 받는 인자의 문자열
// argv[0] : 실행하는 파일(copyFunc.c)
// argv[1] : 복사할파일.txt
// argv[2] : 저장할파일.txt
{

	int n, fdIn, fdOut;
	char buf[BUFFSIZE];
	int byteCount;

	if(argc<3){ 
		//write(2, "Usage : copy file1 file2\n",25);	// 방법1: stderr = 2
		perror("Usage : copy file1 file2");		// 방법2: perror (stdio.h에 포함됨)
								// 경고메시지 뒤에 : Success가 뜬다 + error번호를 return한다.  [에러번호 출력에 적합하다]
								// Success는 왜뜨지?
								// perror 자세히 알아보기
		return -1;
	}

	// 원본 파일 열기
	if((fdIn = open(argv[1],O_RDONLY))<0)	//파일 디스크립터가 이러면 에러
	{
		perror(argv[1]);
		
		return -1;
	}

	// 새로 생성되는 파일 열기
	if((fdOut = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR))<0)
	{
		perror(argv[2]);
		return -1;
	}

	while((byteCount = read(fdIn,buf,sizeof(buf)))>0)
		write(fdOut,buf,byteCount);
		
	close(fdIn);
	close(fdOut);

/*
open 함수에 사용되는 인자들
O_RDONLY readonly
O_WRONLY writeonly
O_RDWR read and write 
O_CREAT		해당파일이 없으면 생성합니다, 파일을 생성하게 된다면 파일의 접근 권한을 지정하기 위해 접근 권한 값을 추가해야 합니다.ex)0644
O_EXCL 		O_CREAT 를 사용했을 때, 파일이 이미 있어도, 열기가 가능하여 쓰기를 하면 이전 내용이 사라집니다.
O_TRUNC		기존 내용을 모두 삭제합니다.
O_APPEND	파일을 추가하여 쓰기가 되도록 open 후에 쓰기 포인터가 파일의 끝에 위치하게 됩니다.
O_NOCITTY	열기 대상이 터미널일 경우, 이 터미널이 플로그램의 제어 터미널로 할당하지 않습니다.
O_NONBLOCK	읽을 내용이 없을 때에는 읽을 내용이 있을 때까지 기다리지 않고 바로 복귀합니다.
		즉 default인 BLOCK일땐 텍스트파일이 비어있으면 복사 X, NONBLOCK을 스면 텍스트파일이 비어있어도 복사를 한다.
O_SYNC		쓰기를 할 때, 실제 쓰기가 완료될 때 까지 기다립니다. 즉, 물리적으로 쓰기가 완료되어야 복귀하게 됩니다.
O_NOATIME	read()시에 파일 최종접근시간을 갱신하지 않는다.[inode의 최초생성 수정시간 접근시간] write하면 갱신되버림, 읽고 바로나왔을때!!
		[설명이 애매하다, 다시 자세히 검색해보자]
*/
	

	return 0;
}
