#include <stdio.h>

// fopen fread fwrite fclose 와 open read write close의 차이는 어떤 Buffer 를 사용하느냐!?!

#define BUFSIZE 1024
int main(int argc, char **argv)
{
	int byteCount;
	FILE *in, *out;
	char buf[BUFSIZE];

/*
	FILE 구조체? stdio.h 에 포함
	struct _iobuf {
		char *_ptr;
		int _cnt;
		char *_BASE;
		int _flag;
		int _file;
		int _charbug;
		int _bufsize;
		char *_tmpfname;
		};
	typedef struct _iobuf FILE;
*/



	// 실행시 paremeter의 입력(갯수)이 정상인지 check
	if(argc!=3)
	{
		//write(2, "Usage : copy file1 file2\n",strlen("경고메시지길이"));과 동일한 기능
		fprintf(stderr, "Usage : fcopy file1 file2\n");
		return -1;
	}

	// 원본파일을 열기
	// bin모드와 txt모드의 차이 구분하기 (이진파일!!)
	// ex)
	/* int ch;
	   if((in=fopen("text.bin", "rb"))==NULL){  // 읽기 전용으로 열기
	   fputs("Error",stderr);
	   exit(1);
	   }

	   while((ch=fgets(in)) != EOF) {
	   printf("%02X ", ch);
	   }
	*/

	
	if((in=fopen(argv[1],"r"))==NULL)
	{
		perror(argv[1]);
		return -1;
	}

	// 대상파일을 열기
	if((out = fopen(argv[2],"w"))==NULL)
	{
		perror(argv[2]);
		return -1;
	}

	while(((byteCount = fread(buf,size(char),BUFSIZE,in))>0)
		fwrite(buf, sizeof(char), byteCount, out);

	fclose(in);
	fclose(out);


	return 0;
}
