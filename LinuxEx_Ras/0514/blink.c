#include <wiringPi.h>
int main (void)
{
	wiringPiSetup () ; // essential sentence for wiringPi !! 
	pinMode (0, OUTPUT) ; // and typing this sentence next!!
	
	for (;;)
    {
	digitalWrite (0, HIGH) ; delay (500) ;
	digitalWrite (0,  LOW) ; delay (500) ;
	}
	return 0 ;
}

//	How to compile?
//	gcc -o blink blink.c (X)
//	gcc -o blink blink.c -l라이브러리명(wiringPi in Here)
		
