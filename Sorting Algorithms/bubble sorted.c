#include<stdio.h>
int main ()
{
        int i ,j;

        int kill[2000];
        for (i=0;i<2000;i++)
        {
     kill[i] =20000-(i*1);
        }
        printf("\n===== %d\n" ,sizeof (kill)) ;

        printf("\n Before Sorting \n\n") ;
        for (i=0;i<2000;i++)
        printf("\n value at %d -- %d ",i,kill[i] ) ;
        BubbleSort(kill,2000) ;
        printf("\n After Sorting \n\n") ;
        for (i=0;i<2000;i++)
        printf("\nvalue at %2d -- %d ",i,kill[i] ) ;
}



void  BubbleSort(int arr[] , int size)
{
    int i ,j;
    for (j=size-1 ; j>=1 ; j--)
    {
        for (i=0 ; i<=j-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
             arr[i]=arr[i]+arr[i+1] ;
             arr[i+1]= arr[i]-arr[i+1] ;
             arr[i]=arr[i]-arr[i+1] ;
            }
        }
    }// return arr;
}
