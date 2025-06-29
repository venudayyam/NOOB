
#include<stdio.h>
#include<stdlib.h>

void insertion_sort( int * , int ) ;
void print_array( int * , int ) ;
void swap( int * , int , int ) ;

int main()
{
	int arr[4] ;
	int i ;

	for ( i=0 ; i<4 ; i++)
		arr[i] = -(rand()%80) ;

	printf ("Before \n") ;
	print_array( arr , 4 ) ;
	insertion_sort(arr , 4) ;
	printf ("\nAfter \n") ;
	print_array( arr ,4 ) ;

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

void insertion_sort ( int * arr , int size )
{
	int i , j ;

	if ( arr==NULL)
		return ;

	for ( i=1 ; i< size ; i++)
	{
		for ( j=i ; j>0 ; j-- )
		{
			if ( arr[j]< arr[j-1] )
				swap( arr , j , j-1 ) ;
			else
				break ;
		}
	}
}


void print_array( int * arr , int size )
{
	int i  ;

	for (i=0 ; i<size ; i++)
		printf ("\narr[%2d] = %d",i , arr[i] ) ;
}
