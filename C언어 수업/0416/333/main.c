#include <stdio.h>
#include "one.h"    // �ּ��ص� ���డ�� BUT �־�ߵȴ�
#include "left.h"   // �ּ��ص� ���డ�� BUT �־�ߵȴ�
#include "right.h"  // �ּ��ص� ���డ�� Why?!?! (��������� �ڵ����� ������?!?!)
                    // �׷��� �־�ߵȴ�

//int get_bank();   // �Լ��� ����� �տ� �׻� extern�� �ִٰ� ����!!! (�����Ȱ�찡 ��)

//void set_bank();  // �Լ��� ����� �տ� �׻� extern�� �ִٰ� ����!!! (�����Ȱ�찡 ��)


int main()
{

	int withdraw;
	
	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);
	
	return 0;
}