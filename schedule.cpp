#include "schedule.h"

schedule::schedule()
{
    first = last = today = NULL ;
    maxindex = 0 ;
}
schedule::schedule(const schedule &s)
{
    first = s.first ;
    last = s.last ;
    today = s.today ;
    maxindex = s.maxindex;
}
void schedule::settoday(int ty, int tm, int td)
{
    int i ;
    addevent(ty,tm,td,0,0,"TODAY",1) ;
}
bool schedule::addevent(int ty, int tm,int td, int th,int tmi, char des[],int i)
{
    date * current ,*newd;
    newd = new date (ty,tm,td,th,tmi) ;
    //dodanie obecnej daty
    if (i == 1) today = newd ;
    newd->ev = new event(des) ;
    //pierwszy element na liscie
    if ( first == NULL )
    {
        first = last = newd ;
        first->prev = NULL ;
        last->next = NULL ;
        first->index = 1 ;
    } else
    {
        if ( *newd < *first )
        {
            first->prev = newd ;
            newd->next = first ;
            first = newd ;
            newd->index = ++maxindex ;
            return 1 ;
        }
        if ( *newd > *last )
        {
            newd->index = ++maxindex ;
            newd->prev = last ;
            last->next = newd ;
            last = newd ;
            return 1 ;
        }
        current = first ;
        while ( current != NULL )
        {
            if ( *newd < *current)
            {
                newd->index = ++maxindex ;
                newd->prev = current->prev ;
                current->prev->next = newd ;
                current->prev = newd ;
                newd->next = current ;
                break ;
            }
            if (*newd == *current)
            {
                return false;
            }
            current = current->next ;
        }

    }
    return true ;
}
bool schedule::delevent(int i)
{
    date *current ;
    current = first ;
    //szukanie elementu do usuniecia
    while ( current != NULL )
    {
        if ( current->index == i )
        {
            //nie mozna usunac obiektu z obecna data
            if (current == today) return false ;
            //usuniecie pierwszego i ostatniego elementu
            if (current == first)
            {
                first = first->next ;
                first->prev = NULL ;

            }else if (current == last)
            {
                last = current->prev ;
                last->next = NULL ;

            }else
            {
                current->prev->next = current->next ;
                current->next->prev = current->prev ;
            }
            delete current->ev ;
            delete current ;
            return 1 ;
        }
        current = current->next ;
    }
    return 0 ;
}
bool schedule::changedate(int i,int ty,int tm,int td, int th,int tmi)
{
    date * current ;
    event temp ;
    current = first ;
    while ( current != NULL )
    {
        if ( current->index == i )
        {
            //uniemozliwienie przypadkowej zmiany aktualnego dnia
            if (current == today) return false ;
            temp = *(current->ev) ;
            delevent(i) ;
            addevent(ty,tm,td,th,tmi,temp.description,0) ;

            return true ;
        }
        current = current->next ;
    }
    return false;

}
bool schedule::shiftevent(int i, int ty,int tm,int td,int th,int tmi)
{
    date * current ;
    date ch ;
    event temp ;
    current = first ;
    while ( current != NULL )
    {
        if ( current->index == i )
        {
            if (current == today) return false ;
            temp = *(current->ev) ;
            ch = *(current) ;
            delevent(i) ;
            addevent(ch.year + ty,ch.month + tm,ch.day + td,ch.hour + th , ch.minute + tmi , temp.description,0) ;
            return true ;
        }
        current = current->next ;
    }
    return false;

}
void schedule::seeweek()
{
    date * current, *firstthisweek ;
    // rozpoczecie od dnia dzisiejszego
    current = today ;
    // szukanie pierwszego dnia biezacego tygodnia
    while ( current != first && current->prev->dayofweek <= current->dayofweek && (*today - *(current->prev)) < 7 )
    {
        current = current->prev ;
    }
    firstthisweek = current ;
    //drukowanie wszystkich wydarzen w obecnym tygodniu
    while( current != NULL && *current - *firstthisweek < 7 && (current->dayofweek >= firstthisweek->dayofweek))
        {
            //pominiecie obiektu z obecna data (i wszystkich poprzednich)
            if (*(current->ev) == *(today->ev))
            {
                current = current->next ;
                continue ;
            }
            //jezeli jest to kolejne wydarzenie tego dnia, wyswietla sie tylko godzina
            if ( current == first || (*current) - *(current->prev) > 0 || current->prev == today)
            {
                cout << *current << endl ;
            }
            cout << "No. " << current->index << " " ;
            cout << setfill('0') << setw(2) << current->hour << ":" ;
            cout << setfill('0') << setw(2) << current->minute << "\t" << *(current->ev) << endl ;
            current = current->next ;
        }
}
void schedule::seemonth()
{
    date * current ;
    current = today ;
    //pierwsze wydarzenie w miesiacu
    while ( current->prev != NULL && current->prev->month == today->month )
    {
        current = current->prev ;
    }
    cout << setw(40)<< today->months[today->month] <<" "<< today->year << endl ;
    while ( current != NULL && current->month == today->month)
    {
        if ( current == first || *current - *(current->prev) > 0 || current->prev == today)
        {
                if (current == today)
                {
                    current = current->next ;
                    continue ;
                }
                cout << current->weekdays[current->dayofweek] <<" "<<  current->day << endl ;
            }

            cout << "No. " << current->index << "  " ;
            cout << setfill('0') << setw(2) << current->hour << ":" ;
            cout << setfill('0') << setw(2) << current->minute <<"\t"<<  *(current->ev) << endl ;
            current = current->next ;
    }

}
void schedule::fileseeweek()
{

    ofstream fout ( "weeklyschedule.txt" ) ;
    fout << "Weekly schedule" << endl ;
    date * current, *firstthisweek ;
    current = today ;
    while ( current != first && (current->prev->dayofweek < current->dayofweek ||
            current->prev->dayofweek == current->dayofweek) && today - current->prev < 7 )
    {
        current = current->prev ;
    }
    firstthisweek = current ;
    while( current != NULL && *current - *firstthisweek < 7 && (current->dayofweek >= firstthisweek->dayofweek))
        {
            if ( current == first || (*current) - *(current->prev) > 0 || current->prev == today)
            {
                if (*current == *today) continue ;
                fout << current->weekdays[current->dayofweek] << " " << current->day << endl ;
            }
            fout << current->hour << ":" << current->minute << " " << current->ev->description << endl ;
            current = current->next ;
        }
        fout.close() ;
}
void schedule::fileseemonth()
{
    ofstream fout ("monthlyschedule.txt") ;
    fout << "Monthly schedule" << endl ;
    date * current ;
    current = today ;
    while ( current->month == today->month && current->prev != NULL  )
    {
        current = current->prev ;
    }
    fout << endl << today->months[today->month] <<"\t"<< today->year << endl ;
    while ( current != NULL && current->month == today->month)
    {
        if ( current == first || current->day > current->prev->day || current->prev == today)
            {
                fout << current->weekdays[current->dayofweek] <<"\t"<<  current->day << endl ;
            }
            fout << current->hour << ":" << current->minute <<"\t"<< current->ev->description << endl ;
            current = current->next ;
    }
    fout.close() ;

}
bool schedule::findevent(const date &d)
{
    date *current ;
    current = first ;
    while ( current != NULL)
    {
        if ( (*current)  == d ) return true ;
        current = current->next ;
    }
    return false ;
}
schedule::~schedule()
{
    date * current ;
    current = first->next ;
    while (current != NULL)
    {

        delete current->prev->ev ;
        delete current->prev ;
        current = current->next ;
    }
    delete last->ev;
    delete last ;
}
