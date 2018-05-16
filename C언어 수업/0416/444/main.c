#include <stdio.h>

#include "hd.h"

//typedef struct eag{				// 구조체가 두개정의되어있어 에러가 발생할 것 같지만
//	int fir;					// 구조체는 메모리가 아닌 선언이므로 에러발생XXXX (선언은 많이써도 상관없다!!)
//	int sec;					// but, 보기 안좋으므로 헤더파일로 넣는게 굿굿굿
//}TAG;

TAG put (int a, int b);

int main()
{
	TAG rlt;
	
	rlt = put(10,5);
	
	printf("%d %d\n", rlt.fir, rlt.sec);

	return 0;
}