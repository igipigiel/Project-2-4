#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include "date.h"
#include "event.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
using namespace std;

//klasa obslugujaca terminarz

class schedule {
    date *first ;
    date *last ;
    date * today ;
    // przechowuje indeks ostatnio dodanego obiektu
    int maxindex ;
public:
    schedule() ;
    schedule(const schedule &) ;
    //funkcja ustawiajaca obecna date
    void settoday(int ty,int tm, int td) ;
    //funkcja dodajaca wydarzenia do terminarza, ostatni argument sluzy tylko do dodania obecnej daty
    bool addevent(int ty,int tm,int td, int th,int tmi,char des[], int i) ;
    // funkcja usuwa element wybrany po indeksie
    bool delevent(int i) ;
    //przesuwa wydarzenie na konkretna date
    bool changedate(int i,int ty,int tm,int td, int th,int tmi) ;
    // przesuwa wydarzenie o konkretna ilosc lat,miesiecy,dni,godzin,minut
    bool shiftevent(int, int ty,int tm,int td,int th,int tmi ) ;
    //wyswietla wydarzenia zapisane na obecny tydzien
    void seeweek() ;
    void seemonth() ;
    void fileseeweek() ;
    void fileseemonth() ;
    inline date * getfirst() const {return first ;} ;
    bool findevent(const date &) ;
    ~schedule() ;

    };



#endif // SCHEDULE_H_INCLUDED
