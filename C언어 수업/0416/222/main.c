#include <stdio.h>

int get_bank();   // �Լ��� ����� �տ� �׻� extern�� �ִٰ� ����!!! (�����Ȱ�찡 ��)

void set_bank();  // �Լ��� ����� �տ� �׻� extern�� �ִٰ� ����!!! (�����Ȱ�찡 ��)


int main()
{

	int withdraw;
	
	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);
	
	return 0;
}



// �������� ��Ŭ�� ����
// �ƴϸ� �ٸ��ſ��ٰ� ��Ŭ�� "������Ʈ ��ε�"