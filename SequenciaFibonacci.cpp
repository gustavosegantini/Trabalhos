
#include <stdio.h>

#include <curses.h>

int fibo(int num)
{
   if(num==1 || num==2)
       return 1;
   else
       return fibo(num-1) + fibo(num-2);
}

int main()
{
   int n,i;
   printf("Quantidade: ");
   scanf("%d", &n);
   printf("\nA sequência: \n");
  
    for(i=0; i<n; i++)
       printf("%d ", fibo(i+1));
   getch();
}

