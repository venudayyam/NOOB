#include<stdio.h>

int main ()
{
    int arr[10] ;
    int i; printf("\n");
    for (i=0;i<10;i++)
    {
        printf(" Enter the %d value - ",i+1);
        scanf("%d" ,&arr[i]) ;
    }
    int j,temp;

  for (i=1;i<=9;i++)
  {
    j=i;
    while(j>0 && arr[j]<arr[j-1])
    {
        temp=arr[j];
        arr[j] =arr[j-1] ;
        arr[j-1] =temp;
        j=j-1;
    }
  }

    for (i=0;i<10;i++)
    {
        printf("\n%d",arr[i]);
    }
}
