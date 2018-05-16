#include <stdio.h>

int get_bank();   // 함수의 선언부 앞에 항상 extern이 있다고 생각!!! (생략된경우가 多)

void set_bank();  // 함수의 선언부 앞에 항상 extern이 있다고 생각!!! (생략된경우가 多)


int main()
{

	int withdraw;
	
	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);
	
	return 0;
}



// 엉켰을땐 우클릭 정리
// 아니면 다른거에다가 우클릭 "프로젝트 언로드"