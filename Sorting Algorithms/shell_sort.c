

#include<stdio.h>
#include<stdlib.h>

void shell_sort( int * , int ) ;
void print_array( int * , int ) ;
void swap( int * , int , int ) ;

int main()
{
	int arr[150] ;
	int i ;

	for ( i=0 ; i<150 ; i++)
		arr[i] = (rand()%8000) ;

	printf ("Before \n") ;
	print_array( arr , 150 ) ;
	shell_sort(arr , 150) ;
	printf ("\nAfter \n") ;
	print_array( arr ,150 ) ;

}



void swap( int * arr , int x , int y )
{
	int temp ;


	temp  = arr[x] ;
	arr[x] = arr[y] ;
	arr[y] = temp ;
}


/**
 *	Does  : Sorts the Given Array in Ascending Order
 *	Takes : Name of the Array to be Sorted with Valid Size
 */

void shell_sort ( int * arr , int size )
{
	int incr =1 ;
	int i , j ;

	if ( arr==NULL ) return ;

	/* finding the pattern */
	while ( 2*incr <= size )
		incr *=2 ;
	incr-- ;

	while ( incr >=1 )
	{
		for ( i= incr ; i< size ; i++)
		{
			for ( j=i ; j>= incr  ; j-=incr )
			{
				if ( arr[j] < arr[j-incr] )
					swap( arr , j , j-incr ) ;
				else
					break ;
			}
		}
		incr/=2 ;
	}

}


void print_array( int * arr , int size )
{
	int i  ;

	for (i=0 ; i<size ; i++)
		printf ("\narr[%2d] = %d",i , arr[i] ) ;
}
