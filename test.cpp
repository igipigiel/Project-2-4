#include "test.h"

bool test1()
{
    char t[] = "Abc" ;
    schedule my ;
    date d(2018,12,10,12,12) ;
    my.addevent(2018,12,10,12,12,t,0) ;
    if ( d == *(my.getfirst()) ) return true ;
    else return false ;
}
bool test2()
{
    char t[] = "Abc" ;
    schedule my ;
    date d(2018,12,10,12,12) ;
    my.addevent(2018,12,10,12,12,t,0) ;
    my.addevent(2018,12,14,13,10,t,0) ;
    my.delevent(1) ;
    if ( !(my.findevent(d)) ) return true ;
    else return false ;
}
bool test3()
{
    char t[] = "Abc" ;
    schedule my ;
    date d(2018,12,10,12,12) ;
    my.addevent(2018,12,8,8,8,t,0) ;
    my.addevent(2018,12,14,13,10,t,0) ;
    my.changedate(1,2018,12,10,12,12) ;
    if ( my.findevent(d) ) return true ;
    else return false ;
}
bool test4()
{
    char t[] = "Abc" ;
    schedule my ;
    date d(2018,12,10,12,12) ;
    my.addevent(2018,12,8,12,12,t,0) ;
    my.addevent(2018,12,14,13,10,t,0) ;
    my.shiftevent(1,0,0,2,0,0) ;
    if ( my.findevent(d) ) return true ;
    else return false ;
}

void testschedule()
{
    char temp[][MAXLEN] {"Study","Do laundry" ,"Meeting with John","Call grandma","Go to the gym","Dinner with Alex",
    "Presentation at work","Grocery shopping"} ;
    int tab[] = {0,0,4,3,0} ;
    schedule my ;
    my.settoday(2018,5,6) ;
    cout << "Adding events" << endl ;
    my.addevent(2018,5,5,13,30,temp[1],0) ;
    my.addevent(2018,5,6,12,00,temp[2],0) ;
    my.addevent(2018,5,8,10,00,temp[4],0) ;
    my.addevent(2018,5,9,9,13,temp[5],0) ;
    my.addevent(2018,4,20,11,13,temp[6],0) ;
    my.addevent(2018,5,7,11,20,temp[3],0) ;
    cout << "Monthly schedule" << endl ;
    my.seemonth() ;
    cout << "Shifting event no. 3 - 4 days 3 hours later" << endl ;
    my.shiftevent(3,tab[0],tab[1],tab[2],tab[3],tab[4]) ;
    cout << "Shifting event no. 5 to 13 May 13:00" << endl ;
    my.changedate(6,2018,5,13,13,0) ;
    cout << "Weekly schedule:" << endl ;
    my.seeweek() ;
    cout << "Deleting event no. 2" << endl ;
    my.delevent(2) ;
    cout << "Weekly schedule:" << endl ;
    my.seeweek() ;
    cout << "Adding new event on 12 May 2018 15:30" << endl ;
    my.addevent(2018,5,12,15,30,temp[7],0) ;
    my.settoday(2018,5,13) ;
    cout << "Next week's schedule - in the file 'weeklyschedule.txt'" << endl ;
    my.fileseeweek() ;


}
void testschedule2()
{
    ofstream fout ;
    char temp[][MAXLEN] {"Study","Do laundry" ,"Meeting with John","Call grandma","Go to the gym","Dinner with Alex",
    "Presentation at work","Grocery shopping"} ;
    int tab[] = {0,0,1,3,0} ;
    schedule my ;
    my.settoday(2020,2,25) ;
    cout << "Adding events" << endl ;
    my.addevent(2020,2,26,13,30,temp[1],0) ;
    my.addevent(2020,2,27,12,00,temp[2],0) ;
    my.addevent(2020,2,28,10,00,temp[4],0) ;
    my.addevent(2020,2,29,9,13,temp[5],0) ;
    my.addevent(2020,3,1,11,13,temp[6],0) ;
    my.addevent(2020,3,2,11,20,temp[3],0) ;
    cout <<endl << "Monthly schedule" << endl ;
    my.seemonth() ;
    cout << "Shifting event no. 3 - 1 day 3 hours later" << endl ;
    my.shiftevent(3,tab[0],tab[1],tab[2],tab[3],tab[4]) ;
    cout << "Shifting event no. 5 to 3 March 13:00" << endl ;
    my.changedate(6,2020,3,3,13,0) ;
    cout << endl << "Weekly schedule:" << endl ;
    my.seeweek() ;
    cout << "Deleting event no. 2" << endl ;
    my.delevent(2) ;
    cout << endl << "Weekly schedule:" << endl ;
    my.seeweek() ;
    cout << "Adding new event on 26 February 2020 15:30" << endl ;
    my.addevent(2020,2,26,15,30,temp[7],0) ;
    my.settoday(2020,3,2) ;
    cout << "Next week's schedule - in the file 'weeklyschedule.txt'" << endl ;
    fout << "Weekly schedule" << endl ;
    my.fileseeweek() ;
}

bool correctinput(int& y,int &m,int &d,int &h, int &mi)
{
    while ( y < 2016 )
    {
        cout << "Please enter a correct year" << endl ;
        if ( number()) cin >> y ;
    }
    while ( m > 12 || m <= 0 )
    {
        cout << "Please enter the month correctly" << endl ;
        if ( number()) cin >> m ;
    }
    while ( d <= 0 || d > 31)
    {
        cout << "Please enter the day correctly" << endl;
        if ( number()) cin >> d ;
    }
    while ( y%4 != 0 && m ==2 && d > 28 )
    {
        cout << "There's no such day this year" << endl ;
        if ( number()) cin >> d ;
    }
    while ( h < 0 || h > 24 )
    {
        cout << "Please enter the hour correctly" << endl ;
        if ( number()) cin >> h ;
    }
    while ( mi < 0 && mi > 60 )
    {
        cout << "Please enter the minute correctly" << endl ;
        if ( number()) cin >> mi ;
    }
    return true ;
}
bool number()
{
    char c ;
    c = getc(stdin) ;
    if ( isdigit(c))
    {
        ungetc(c,stdin) ;
        return true ;
    } else return false ;
}
