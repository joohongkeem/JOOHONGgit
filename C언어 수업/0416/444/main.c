#include <stdio.h>

#include "hd.h"

//typedef struct eag{				// ����ü�� �ΰ����ǵǾ��־� ������ �߻��� �� ������
//	int fir;					// ����ü�� �޸𸮰� �ƴ� �����̹Ƿ� �����߻�XXXX (������ ���̽ᵵ �������!!)
//	int sec;					// but, ���� �������Ƿ� ������Ϸ� �ִ°� �±±�
//}TAG;

TAG put (int a, int b);

int main()
{
	TAG rlt;
	
	rlt = put(10,5);
	
	printf("%d %d\n", rlt.fir, rlt.sec);

	return 0;
}