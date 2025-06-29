

#include<stdio.h>
#include<stdlib.h>

void bubble_sort( int * , int ) ;
void print_array( int * , int ) ;
void swap( int * , int , int ) ;

int main()
{
	int arr[14] ;
	int i ;

	for ( i=0 ; i<14 ; i++)
		arr[i] = (rand()%8000) ;

	printf ("Before \n") ;
	print_array( arr , 14 ) ;
	bubble_sort(arr , 14) ;
	printf ("\nAfter \n") ;
	print_array( arr ,14 ) ;

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

void bubble_sort ( int * arr , int size )
{
	int i , j ;

	if ( arr==NULL ) return ;

	for ( i=size-1 ; i>0 ;  i-- )
	{
		for ( j=0 ; j< i ; j++ )
		{
			if (arr[j]> arr[j+1] )
				swap( arr , j , j+1 ) ;
		}
	}
}


void print_array( int * arr , int size )
{
	int i  ;

	for (i=0 ; i<size ; i++)
		printf ("\narr[%2d] = %d",i , arr[i] ) ;
}
