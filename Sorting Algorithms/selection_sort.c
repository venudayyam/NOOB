
#include<stdio.h>
#include<stdlib.h>

void selection_sort( int * , int ) ;
void print_array( int * , int ) ;
void swap( int * , int , int ) ;

int main()
{
	int arr[20] ;
	int i ;

	for ( i=0 ; i<20 ; i++)
		arr[i] = -(rand()%500) ;

	printf ("Before \n") ;
	print_array( arr , 20 ) ;
	selection_sort(arr , 20) ;
	printf ("\nAfter \n") ;
	print_array( arr ,20 ) ;

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

void selection_sort ( int * arr , int size )
{
	int index , i , j ;

	if (arr==NULL )
		return ;
	for ( i=0 ; i< size-1 ; i++ )
	{
		index=i ;
		for ( j=i+1 ; j< size ; j++ )
		{
			if ( arr[index]>arr[j] )
				index=j ;
		}
		swap( arr , i , index ) ;
	}
}


void print_array( int * arr , int size )
{
	int i  ;

	for (i=0 ; i<size ; i++)
		printf ("\narr[%2d] = %d",i , arr[i] ) ;
}
