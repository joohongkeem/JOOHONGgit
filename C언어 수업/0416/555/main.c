#include <stdio.h>

#include "common.h"
#include "dup.h"

// �̰� �Ѵ� �����ϸ� �����߻�(error C2011: 'tag' : 'struct' ���� ������)
// Why? main���� TAG�� ��������Ƿ� common.h�� include�߰�
//				  put�̶�� �Լ��� ��������Ƿ� dup.h�� include�ߴ�.
//				  dup.c������ TAG�� ��������Ƿ� common.h�� include�ߴ�.
//                dup.h������ put�Լ��� ��������Ƿ� common.h�� include
//				  �ʿ��Ѱ͸� include�ߴµ� �����߻�!! 
//                �� ��, main�Լ����� include������ ����ü �����ǵǼ� �����߻�!!
//				  ifn, define�Լ��� �������.



int main()
{
	TAG rlt;
	
	rlt = put(10,5);
	
	printf("%d %d\n", rlt.fir, rlt.sec);

	return 0;
}