#include <stdio.h>
#include "one.h"    // 주석해도 실행가능 BUT 넣어야된다
#include "left.h"   // 주석해도 실행가능 BUT 넣어야된다
#include "right.h"  // 주석해도 실행가능 Why?!?! (헤더파일이 자동으로 잡힌다?!?!)
                    // 그래도 넣어야된다

//int get_bank();   // 함수의 선언부 앞에 항상 extern이 있다고 생각!!! (생략된경우가 多)

//void set_bank();  // 함수의 선언부 앞에 항상 extern이 있다고 생각!!! (생략된경우가 多)


int main()
{

	int withdraw;
	
	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);
	
	return 0;
}