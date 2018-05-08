#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <cstdio>
#define MAXLEN 40
using namespace std ;

// klasa do reprezentacji wydarzenia

class event {
    char description[MAXLEN] ;
public:
    event() ;
    event(char []) ;
    event(const event &) ;
    void operator=(const event &) ;
    bool operator == (const event &) ;
    friend ostream & operator<<( ostream & ,const event &) ;
    friend class schedule ;
    };



#endif // EVENT_H_INCLUDED
