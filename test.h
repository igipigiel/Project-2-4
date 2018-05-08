#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <ctype.h>
#include "schedule.h"
using namespace std ;

bool correctinput(int y,int m,int d,int h, int mi) ;
bool number() ;
void testschedule();
void testschedule2() ;
bool test1() ; // test dodawania elementu
bool test2() ; //test usuwania elementu
bool test3() ; // test przesuwania na konkretna date
bool test4() ; //test przesuwania o ilosc lat,miesiecy,dni...


#endif // TEST_H_INCLUDED
