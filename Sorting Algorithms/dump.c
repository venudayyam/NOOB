//void sort(int x[ ]);
   main()
   {
       int i;
       int marks[5] = {40, 90, 73, 81, 35};

       printf("Marks before sorting\n");
       for(i = 0; i < 5; i++)
          printf("%d ", marks[i]);
       printf("\n\n");

       sort (marks);
       printf("Marks after sorting\n");
       for(i = 0; i < 5; i++)
          printf("%4d", marks[i]);
       printf("\n");
   }
   void sort(int x[ ])
   {
       int i, j, t;

       for(i = 1; i <= 5-1; i++)
          for(j = 1; j <= 5-i; j++)
             if(x[j-1] >= x[j])
             {
                t = x[j-1];
                x[j-1] = x[j];
                x[j] = t;
             }
   }
