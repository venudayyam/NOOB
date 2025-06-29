#include<stdio.h>
int main ()
{
        int i ,j;

        int kill[20];
        for (i=0;i<20;i++)
        {
            kill[i] =rand()%98 ;
        }
        printf("\n===== %d\n" ,sizeof (kill)) ;

        printf("\n Before Sorting \n\n") ;
        for (i=0;i<20;i++)
        printf("\n value at %d -- %d ",i,kill[i] ) ;
        SelectionSort(kill,20) ;
        printf("\n After Sorting \n\n") ;
        for (i=0;i<20;i++)
        printf("\nvalue at %2d -- %d ",i,kill[i] ) ;
}



void  SelectionSort(int arr[] , int size)
{
    int i ,j ;
    int temp_index;

for (j=0;j<size-1;j++) {

    temp_index=j;
    for (i=j+1;i<=size-1;i++)
    {
        if (arr[i] < arr[temp_index])
        {
            temp_index= i ;
        }
    }

    if (temp_index!=j )
    {
        arr[j]=arr[j]+arr[temp_index] ;
        arr[temp_index]=arr[j]-arr[temp_index] ;
        arr[j]=arr[j]-arr[temp_index] ;

    }

}









}
