// 헤더파일 추가하기
// 솔류션탐색기의 솔루션 우클릭 - 추가 - 새프로젝트
// 두꺼운 글씨가 주 프로그램(얇은 글씨 컴파일 x)
// 얇은글씨 우클릭 - 시작프로젝트로 설정  하면 주프로그램이 바껴서 컴파일이 된다

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