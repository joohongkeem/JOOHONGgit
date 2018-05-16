#include <stdio.h>

#include "common.h"
#include "dup.h"

// 이걸 둘다 포함하면 에러발생(error C2011: 'tag' : 'struct' 형식 재정의)
// Why? main에선 TAG를 사용했으므로 common.h를 include했고
//				  put이라는 함수를 사용했으므로 dup.h를 include했다.
//				  dup.c에서도 TAG를 사용했으므로 common.h를 include했다.
//                dup.h에서도 put함수를 사용했으므로 common.h를 include
//				  필요한것만 include했는데 에러발생!! 
//                이 때, main함수에서 include때문에 구조체 재정의되서 에러발생!!
//				  ifn, define함수를 사용하자.



int main()
{
	TAG rlt;
	
	rlt = put(10,5);
	
	printf("%d %d\n", rlt.fir, rlt.sec);

	return 0;
}