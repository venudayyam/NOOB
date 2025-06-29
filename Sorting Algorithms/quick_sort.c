

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void quick_sort( int * , int ) ;
void print_array( int * , int ) ;
void swap( int * , int , int ) ;

int main()
{
	int arr[5000] ;
	int i ;

	for ( i=0 ; i<5000 ; i++)
		arr[i] = (rand()%8000) ;

	printf ("Before \n") ;
	print_array( arr , 5000 ) ;
	quick_sort(arr , 5000) ;
	printf ("\nAfter \n") ;
	print_array( arr ,5000 ) ;

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




int partition(int *arr , int first , int last )
{
	if (arr==NULL) return 0;

	int pivot= arr[ (first+last)/2] ;
	int i= first-1 ;
	int j=last+1 ;

	while (true)
	{
		do {
				i++ ;
		} while (arr[i]<pivot) ;

		do {
				j-- ;
		} while (arr[j]>pivot) ;

		if (i<j)
			swap( arr , i , j) ;
		else
			break ;
	}
	return j ;
}

void quick( int *arr , int first , int last )
{
	int split = partition(arr , first, last ) ;

	if ( split> first )
	quick( arr , first , split ) ;
	if ( split+1< last )
	quick( arr , split+1 , last ) ;
}

void quick_sort ( int * arr , int size )
{
	quick(arr , 0 , size-1 ) ;
}


void print_array( int * arr , int size )
{
	int i  ;

	for (i=0 ; i<size ; i++)
		printf ("\narr[%2d] = %d",i , arr[i] ) ;
}
