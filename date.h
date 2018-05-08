#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include "event.h"

using namespace std;

//klasa do reprezentacji daty
// wydarzenia nie moga byc dodawane na wczesniejszy rok niz 2016

class date {
    int year ;
    char months [13][20] = {"0" , "January", "February", "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December" };
    int month ;
    char weekdays[8][20] = {"0" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"} ;
    int dayofweek ;
    int day ;
    int hour ;
    int minute ;
    // wydarzenie zapisane na konkretna date
    event * ev ;
    //poprzedni i nastepny element - potrzebne do utworzenia listy
    date * prev ;
    date * next ;
    // indeks wydarzenia, w kolejnosci dodania, przydatny przy wyborze wydarzenia do przesuniecia, usuniecia
    int index ;
public :
    date() ;
    date(const date &) ;
    date(int y,int m,int d,int h,int mi) ;
    // funkcja oblicza dzien tygodnia na podstawie daty
    int setdayofweek();
    // funkcja zwraca roznice w dniach miedzy dwoma datami, potrzebna przy wyswietlaniu tygodnia
    int operator-(const date &) ;
    void operator=(const date &) ;
    bool operator==(const date &) ;
    bool operator!=(const date &) ;
    bool operator>( const date &) ;
    bool operator<(const date &) ;
    friend ostream & operator<<( ostream & ,const date &) ;
    friend class schedule ;
    ~date() ;
    };


#endif // DATE_H_INCLUDED
