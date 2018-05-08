#include "event.h"

event::event()
{
    description[0] = '\0' ;
}
event::event(char d[])
{
    int i ;
    for ( i = 0 ; i < MAXLEN ; i++)
    {
        description[i] = d[i] ;
    }
}
event::event(const event &e)
{
    int i ;
    for ( i = 0 ; i < MAXLEN ; i++)
    {
        description[i] = e.description[i] ;
    }
}
void event::operator=(const event &e)
{
    int i ;
    for ( i = 0 ; i < MAXLEN ; i++)
    {
        description[i] = e.description[i] ;
    }
}
bool event::operator==(const event &e)
{
    int i ;
    for ( i = 0 ; i < MAXLEN ; i++ )
    {
        if (description[i] != e.description[i] ) return false ;
    }
    return true ;
}
ostream & operator<<( ostream &os ,const event &e)
{
    cout << e.description ;
    return os ;
}

