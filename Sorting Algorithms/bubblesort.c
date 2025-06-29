#include<stdio.h>
#include<stdlib.h>
void print_array ( int* , int ) ;
void input_flush() ;

int main ()
{

	int Invalid =1 ;
	int input_count ;
	int i , j  , temp ;
	int *arr ;

	do
	{
		if ( ! Invalid )
		{
			printf (" Invalid Input.\n") ;
			input_flush() ;
		}
		printf ("\n No of Integers you will give :  " ) ;
	} while ( ( Invalid = scanf( "%d" , &input_count ) )!=1 ) ;


	/* allocating memory */
	arr = ( int *) malloc ( sizeof ( int) * input_count ) ;

	for ( i=0 ; i< input_count ; i++ )
	{
		do
		{
			if ( ! Invalid )
			{
				printf (" Invalid Input.\n") ;
				input_flush() ;
			}
			printf ("\n Arr[%d] : " , i ) ;
		} while ( ( Invalid = scanf( "%d" , arr+i ) )!=1 ) ;

		input_flush() ;
	}

	printf("\nInitial Contents \n") ;
	print_array ( arr , input_count ) ;

	for ( i=input_count-1  ; i>0 ; i-- )
	{
		for ( j=0 ; j< i  ; j++ )
		{
			if ( arr[j] > arr[j+1] )
				temp = arr[j] , arr[j]=arr[j+1] , arr[j+1] = temp ;
		}
	}

	printf("\n\nSorted Contents \n") ;
	print_array ( arr , input_count ) ;

}

void print_array( int * arr , int size )
{
	 int index =0 ;

	 while ( index<size )
	 {
	 	printf ("\n arr[%d] = %d " , index , *arr ) ;
	 	arr++ , index++ ;
	 }
}

void input_flush()
{
	char c ;
	while ( getc(stdin)!='\n' ) ;
}
