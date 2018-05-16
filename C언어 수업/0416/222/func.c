#include "inc.h" // extern으로 가져오던걸 헤더파일이므로 #include로 가져온다

int get_bank()
{
	return passbook; // withdraw
}

void set_bank()
{
	passbook++; // deposit
}

