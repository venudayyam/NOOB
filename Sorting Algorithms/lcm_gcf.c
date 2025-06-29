//      Program to find LCM and HCF  of an array of numbers

#include<stdio.h>

int H_C_F(int , int ) ;
int L_C_M(int , int ) ;

int main ()
{
    int hcf , lcm , i, j , temp ,temp1 , length ;

    printf ("\n Enter the Length of array = ") ;
    scanf ("%d", &length) ;
    int arr[length] ;
    if (length<=1)
    {
       printf("\n Sorry Please Enter atleast two numbers ...!! ") ;
        return ;
    }
    printf ("\n") ;

// reading input values

    for (i=0;i<length ; i++)
    {
        printf(" Element [%d]  == " , i) ;
        scanf ("%d", & arr[i]) ;
    }

// logic to find HCF for array of  numbers

    temp=arr[0] ;
    for (j=1;j<length ; j++)
    {
        hcf = H_C_F(temp , arr[j]) ;
        temp =hcf ;
     }

    printf("\n\n HCF of Numbers == %d" , temp ) ;


// logic to find LCM for array of  numbers

    temp1=arr[0] ;
    for (j=1;j<length ; j++)
    {
        lcm = L_C_M(temp1 , arr[j]) ;
        temp1 =lcm ;
     }

    printf("\n\n LCM of Numbers == %d" , temp1 ) ;


}

int L_C_M (int  x  , int y )
{
    int temp = H_C_F(x, y) ;
    return ((x*y)/temp) ;
}

int H_C_F( int x , int y)
{
    int temp ;
    while (x%y!=0)
    {
        temp=y ;
        y=x%y ;
        x=temp ;
    }
    return y ;
}
