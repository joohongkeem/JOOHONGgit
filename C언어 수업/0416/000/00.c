// ������� �߰��ϱ�
// �ַ���Ž������ �ַ�� ��Ŭ�� - �߰� - ��������Ʈ
// �β��� �۾��� �� ���α׷�(���� �۾� ������ x)
// �����۾� ��Ŭ�� - ����������Ʈ�� ����  �ϸ� �����α׷��� �ٲ��� �������� �ȴ�

#include <stdio.h>

int passbook = 100;

int get_bank()
{
	return passbook; // withdraw
}

void set_bank()
{
	passbook++; // deposit
}

int main()
{

	int withdraw;
	
	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);
}