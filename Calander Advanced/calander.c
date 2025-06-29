    /* A piece of code which could show the calendar for given input date
      *
      * Program that could handle all the exceptional  */

#include<stdio.h>
#include<ctype.h>
#include<windows.h>

int char_check(char , int ) ;     //     &
int syntax_check(char * ) ;      //     checks for invalid string input

int find_day(short , short , long ) ;  // actual logic  to find what day  it is ??

int logical_check(short , short , long ) ;
int logical_inner_check(short , short , long ) ; // checks for valid dd , mm , yy !!

void print_calander(int , short  , long ) ;   // prints calendar

char * set_name(short) ;
void update(char) ;  //  function that helps to flip calender on  k/b input

short dd ;
short mm ;
long yy ;


int main (void)
{
    textbackground(15) ;
    textcolor(2) ;
    char date[11];                      // receive single input from the user rather than 3 separately (dd, mm , yy )
    int check = 0 ;
    printf("\n Hello There !! \n") ;
    do
    {
        textcolor(2) ;
        printf("\n Enter a valid date in dd/mm/yyyy Format  : " );
        textcolor(1) ;
        gets(date) ;
    }  while (syntax_check(date) || strlen(date)!=10 ) ;            // checks whether input string given is valid or not

    char temp[5] ;
    dd    = atoi(strncpy(temp , date  , 2 )) ;
    mm = atoi (strncpy(temp , date+3 , 2 ))  ;
    yy    = atol( strncpy (temp , date+6 , 4 ) ) ;

    check = logical_check(dd ,mm, yy ) ;              // checks whether input d/m/y  are valid or not

    if (check)
    {
        textcolor(1) ;
        getch() ;
        exit(0) ;
    }
    textcolor(12) ;
    printf("\n\n\n Please wait...buddy !!  \n\n I drunk way too much Last Night ..... !!!") ;
    Sleep(1800) ;
    textcolor(1) ;
    printf("\n\n\n\n Ok .. Press Enter ...!!") ;
    getch() ;
    int result = find_day(1 , mm , yy ) ;    // finding first day  of  the month in the given date
    print_calander(result , mm , yy ) ;
    char ch ;
     while (ch=getch() )    //  switch months using  4 and 6  keys
        {
             update(ch) ;
             int result1 = find_day(1 , mm , yy ) ;
             print_calander(result1 , mm , yy ) ;
       }
    gotoxy(1,34) ;
    getch() ;

}



int char_check(char ch , int index )   //  helper for syntax_check
{
    int k= 1 ;
    if (index==2 || index ==5 )
    {
        if (ch=='/' )
            k=0 ;
        return  k ;
    }
    return !isdigit(ch) ;
}

int syntax_check(char * date)     //  to check whether input string  is correct or not
{
    int i;
    int decide=0;
    for (i=0 ;i<10 ; i++)
        decide+= char_check(date[i] , i ) ;    // calling  anther function for help
    return decide;
}

int  find_day (short dd , short mm , long yy )   /// Logic to find  what day was/would be  on the given date
{
    long  total_days = 0 ;
    int i=0 ;
    int leap_years=0 ;

    for (i=1 ; i< yy ; i++)                           // Include all leap years  feb- 29 th
    {
         if ( i%400 ==0  ||  i%4==0 && i%100 !=0 )
            leap_years+=1 ;
    }
    total_days = ( yy-1 ) * 365 ;
    total_days+=leap_years;

    switch(mm)
    {
        case 12 :  total_days+=30 ;
        case 11 :  total_days+=31 ;
        case 10 :  total_days+=30 ;
        case   9 :  total_days+=31 ;
        case   8 :  total_days+=31 ;
        case   7 :  total_days+=30 ;
        case   6 :  total_days+=31 ;
        case   5 :  total_days+=30 ;
        case   4 :  total_days+=31 ;
        case   3 :  total_days+=28 ;
        case   2 :  total_days+=31 ;
        case   1 :  total_days+=dd;
    }

    if ( yy%400 ==0  ||  yy%4==0 && yy%100 !=0 )
    {
        if (mm>2 )
        total_days+=1 ;
    }

    return total_days%7 ;

}

int logical_inner_check(short dd , short mm , long yy )      // best helper for logical_check
{
    int k=0 ;
    int leap=0 ;
    if ( yy%400 ==0  ||  yy%4==0 && yy%100 !=0 )
    {
        leap=1 ;
    }

    if (mm== 1 || mm == 3  || mm == 5 || mm == 7 || mm == 8  || mm==10 || mm== 12)
        {
            if (dd>31)
                k=1 ;
            return k ;
       }
     if (mm==2 )
     {
        if (leap && dd>29)
            k=1 ;
        else if (!leap && dd>28)
            k=1 ;
            return k ;
     }
    if ( dd>30 )
        k=1 ;
        return k ;
}

//  checks for invalid input like  entering 29 for February  in non_leap_Year
int logical_check(short dd, short mm , long yy )
{
    int bit=0 ;
    textcolor(12) ;

    if (dd<=0 ||  dd >31 )
        {
            printf("\n Invalid Date !! \n") ;
             return 1 ;
        }
    if (mm<=0 || mm>12)
      {
          printf("\n Invalid Month !!\n") ;
          return 1 ;
      }
        if (logical_inner_check(dd,mm,yy))    // calling another function for help
        {
            printf("\n Invalid Date  %d  for this month !! \n" , dd) ;
            return 1 ;
        }

    return bit ;
}

int last_day_(short first )
{
    switch(first)
    {
        case 1:
        case 3:
        case 5:
        case 7 :
        case 8 :
        case 10 :
        case 12 :  return 31 ;
                            break ;
        case 4 :
        case 6 :
        case 9 :
        case 11 :  return 30 ;
                           break ;
        case 2 :     if ( yy%400 ==0  ||  yy%4==0 && yy%100 !=0 ) return 29 ;
                            else return 28 ;
                            break ;
    }
}

char * set_name(short mm)
{
    switch(mm)
    {
        case 12 :  return "DECEMBER"  ;
        case 11 :  return "NOVEMBER" ;
        case 10 :  return "OCTOBER" ;
        case   9 :  return "SEPTEMBER" ;
        case   8 :  return "AUGUST" ;
        case   7 :  return "JULY" ;
        case   6 :  return "JUNE" ;
        case   5 :  return "MAY" ;
        case   4 :  return "APRIL" ;
        case   3 :  return "MARCH" ;
        case   2 :  return "FEBRUARY" ;
        case   1 :  return "JANUARY" ;
    }
}

void print_calander (int first_day , short  mm , long yy)
{
    int i , j ;
    int axis  ;
    int last_day = last_day_(mm) ;       // function returns the no.of . days in this month
    char * month = set_name(mm) ;   // sets name of the month
    system("cls") ;
    gotoxy(57 ,4 ) ;
    textcolor(1) ;
    printf("%s   %ld" , month , yy) ;
    gotoxy(29 ,8) ;
    printf("%-11s%-11s%-11s%-11s%-11s%-11s%-11s" ,"SUN","MON","TUES" ,"WED","THUR","FRI", "SAT") ;  // header
    gotoxy(30 ,axis=11) ;
    textcolor(2) ;

    for (i=0 ;i<first_day; i++)     // first  week of the month ..
        printf("%-11s","") ;
    for(j=1 ; j<=7-first_day ; j++ )
    {
             textcolor(dd==j ? 12 : 2 ) ;         //
             printf("%-11.2d",j ) ;
    }
    printf("\n") ;
    gotoxy(30 ,axis+=2) ;

    for (j , i=1; j<=last_day ; j++ , i++ )   //  rest of the weeks  in the month
    {
         textcolor(dd==j ? 12 : 2 ) ;
         printf("%-11.2d", j ) ;

         if (i%7==0)
           {
              printf("\n") ;
              axis+=2 ;
              gotoxy(30 ,axis) ;
           }
    }
    gotoxy(55 ,26 ) ;
    textcolor(1) ;
    printf("Time is Precious !!!") ;
    textcolor(1) ;
    gotoxy(130 , 15 ) ;
    printf("Next Month  :");
    textcolor(2) ;
    printf("  num 6 ") ;
    gotoxy(130 , 17 ) ;
    textcolor(1) ;
    printf("Prev Month  :");
    textcolor(2) ;
    printf("  num 4 ") ;
    gotoxy(140 ,28 ) ;

}


void update(char  ch )
{
    if (ch=='6' )
    {
            mm+=1 ;
            if (mm>12)
            {
                 yy+=1 ;
                mm=1 ;
            }
    }
    else if (ch=='4' )
    {
         mm-=1 ;
         if (mm<1)
         {
             yy-=1 ;
             mm=12 ;
        }
    }
    else {
        printf( "\n\n Thank You ..!! \n\n") ;
        exit(0) ;
    }
}
