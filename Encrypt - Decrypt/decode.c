/*
  *    Operating System uses  ASCII of 26 in ASCII table
  *    to store end of Text Format files
  *    C library interprets it and returns EOF = -1
*/

#include<stdio.h>

int main ( int cnt , char *s[] )
{

    FILE * fin , *fout ;
    int ch ;
    int flip  ;
    if ( cnt < 2 ) /* handling possible exceptions  */
    {
        printf ("\nExpects file name with extension \n" ) ;
        return 1 ;
    }
    if ( ( fin = fopen ( s[1] , "r" ) ) == NULL )
    {
        printf ("\nSorry.. File does not exist \n" ) ;
        return 1 ;
    }
/*  actual logic   */
    fout = fopen( "trust.txt" , "w" ) ;
    flip =0 ;

    while ( ( ch = getc(fin) ) != EOF )
    {
         putc( ch+= ( ( ( flip % 2==0 ) ? -20 : -30 ) - ( flip%10 ) ) , fout ) ;
         flip++ ;
    }
    fclose( fin ) ;
    fclose( fout) ;
    remove( s[1] ) ;
    rename( "trust.txt" , s[1] ) ;
    printf ("\nSuccessful ....!! \n ") ;

 }
