
			#include<stdio.h>
			#include<stdlib.h>
			#include<stdbool.h>

			void merge_sort(int *,int) ;
			void print_array(int *,int) ;
			void swap(int *,int,int) ;

			int main()
			{
				int arr[500] ;
				int i ;

				for (i=0 ; i<500 ; i++)
					arr[i] = (rand()%8000) ;

				printf ("Before \n") ;
				print_array(arr,500) ;
				merge_sort(arr,500) ;
				printf ("\nAfter \n") ;
				print_array(arr,500) ;

			}



			void swap(int * arr,int x,int y)
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

			void merge (int * arr,int *temp,int f_start,int f_end,int s_end)
			{
											/*    s_start == f_end+1      */
				int i = f_start ;
				int j = f_end+1 ;
				int k = f_start ;

				while (i<=f_end && j<=s_end)
				{
					if (arr[i]<arr[j])
						temp[k++] = arr[i++] ;
					else
						temp[k++] = arr[j++] ;
				}

				while (i<=f_end)
						temp[k++] = arr[i++] ;

				while (j<=s_end)
						temp[k++] = arr[j++] ;

				for (i=f_start ; i<=s_end ; i++)
				{
					arr[i] = temp[i] ;
				}
			}

			// hello master how r you ....
			void msort(int * arr,int * temp,int first,int last)
			{
				if (first>= last) return ;

				int split = (first+last) / 2 ;

				msort(arr,temp,first,split) ;
				msort(arr,temp,split+1,last) ;
				merge(arr,temp,first,split,last) ;
			}

			void merge_sort (int * arr,int size)
			{
				int *temp = (int*) malloc(sizeof (int) * size) ;
				msort(arr,temp,0,size-1) ;
			}


			void print_array(int * arr,int size)
			{
				int i  ;

				for (i=0 ; i<size ; i++)
					printf ("\narr[%2d] = %d",i,arr[i]) ;
			}
