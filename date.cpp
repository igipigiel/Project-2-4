#include "date.h"

date::date()
{
    year = month = day = hour = minute = 0 ;
    prev = next = NULL ;
    ev = NULL ;

}

date::date(int y,int m,int d,int h, int mi)
{
    year = y ;
    month = m ;
    day = d ;
    hour = h ;
    minute = mi ;
    prev = next = NULL ;
    ev = NULL ;
    setdayofweek() ;
}
date::date(const date &d)
{
    year = d.year ;
    month = d.month ;
    day = d.day ;
    hour = d.hour ;
    minute = d.minute ;
    prev = d.prev ;
    next = d.next ;
    ev = d.ev ;
    dayofweek = d.dayofweek ;
}
int date::setdayofweek()
{
    int r,sum,n ;
    // 2016 rok jako punkt odniesienia - jest to rok przestepny
    int startyear = 2016 ;
    // pierwszy stycznia w 2016 roku by³ czwartkiem
    int i = 4 ;
    int monthdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;
    r = year - startyear ;
    //sum - liczba dni, ktora uplynela od 1 stycznia 2016
    sum = day + i + ((r-1)/4 + 1)*366 + (r - (r-1)/4 - 1)*365;
    for (n = 1 ; n < month ; n++)
    {
        sum += monthdays[n] ;
    }
    // jesli rok przestepny, uwzglednia sie 29 lutego
    if ( year%4 == 0 && month > 2) sum +=1 ;
    dayofweek = sum%7 ;
    if (sum%7 == 0) dayofweek = 7 ;
    return sum ;
}
int date::operator-(const date & d)
{
    int r,sum,n ;
    int startyear = 2016 ;
    int i = 4 ;
    int monthdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;
    r = d.year - startyear ;
    sum = d.day + i + ((r-1)/4 + 1)*366 + (r - (r-1)/4 - 1)*365;
    for (n = 1 ; n < d.month ; n++)
    {
        sum += monthdays[n] ;
    }
    if ( d.year%4 == 0 && d.month > 2) sum +=1 ;
    return setdayofweek() - sum ;

}
void date::operator=(const date & d)
{
    year = d.year ;
    month = d.month ;
    day = d.day ;
    dayofweek = d.dayofweek ;
    hour = d.hour ;
    minute = d.minute;
    prev = d.prev ;
    next = d.next ;
    ev = d.ev ;
}
bool date::operator==(const date &d)
{
    if ( year == d.year && month == d.month && day == d.day && hour == d.hour && minute == d.minute) return true ;
    else return false ;
}
bool date::operator!=(const date &d)
{
    if ((*this) == d) return false ;
    else return true ;
}
bool date::operator<(const date &d)
{
    if ((*this) == d) return false ;
    if (year < d.year) return true ;
    if (year > d.year ) return false ;
    if (year == d.year )
    {
        if(month < d.month) return true ;
        if( month > d.month) return false ;
        if ( month == d.month )
        {
            if ( day < d.day ) return true ;
            if ( day > d.day ) return false ;
            if ( day == d.day )
            {
                if ( hour < d.hour ) return true ;
                if ( hour > d.hour ) return false ;
                if ( hour == d.hour )
                {
                    if ( minute < d.minute ) return true ;
                    if ( minute > d.minute ) return false ;
                }
            }
        }
    }
}
bool date::operator>(const date &d)
{
    if ((*this) < d || (*this) == d) return false ;
    else return true ;
}
date::~date(){}
ostream & operator<<( ostream &os ,const date &d)
{
    cout << d.weekdays[d.dayofweek] << " " << d.day << " " << d.months[d.month] << " " << d.year ;
    return os ;
}
