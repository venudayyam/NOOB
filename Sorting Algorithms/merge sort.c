#include<stdio.h>

int main ()
{
 int arr1[10]={12,15,28,38,39,48,59,68,68,69};
 int arr2[5]={ 5,6,8,9,17,18,66} ;
printf("\nArray 1 elements \n");
int i=0;

 for(i=0;i<10;i++)
printf("\nValue of at %d th position -- %d ",i, arr1[i]);
printf("\n\nArray 2 elements \n");

for(i=0;i<5;i++)
printf("\nValue of at %d th position -- %d ",i, arr2[i]);

     int temp[(sizeof(arr1)+sizeof(arr2))/sizeof (int) ] ;
i=0 ;
int  j=0 , index=0 ;

    while (i<10 && j <5 )
{
        if ( arr1[i] < arr2[j] )
        temp[index++] =arr1[i++] ;    else
            temp[index++]= arr2[j++]  ;
}
while(i<10)
    temp[index++] = arr1[i++] ;

while(j<5) {
    temp[index++] = arr2[j++ ] ;

}












printf("\nAfter sorting \n");
for(i=0;i<15;i++)
printf("\nValue of at %2d th position -- %d ",i , temp[i] );


}



