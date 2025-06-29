// Program to sort an array of elements using Bubble sort

#include<stdio.h>
main ()
{
    int i ,j;
int arr[100];
for (i=0;i<100;i++)
{
    arr[i] =rand()%100;
}
printf("size of arr  %d " , sizeof(arr)/sizeof (int) );
    for (i=0;i<10;i++)
    printf(" value  at %d position - %d\n" , i, arr[i] );

int lastindex=( sizeof(arr)/sizeof(int) ) - 1 ;
printf("\n\n\n\n%d\n",lastindex) ;


            for (j= 9; j>=1 ;j--)
            {
            for (i=0;i<=j-1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                 arr[i]=arr[i]+arr[i+1] ;
                 arr[i+1]= arr[i]-arr[i+1] ;
                 arr[i]=arr[i]-arr[i+1] ;
                }
            }
            }

    printf("\nAfter sorting \n");
    for (i=0;i<10;i++)
    printf(" value  at %d position - %d\n" , i, arr[i] );

}
