#include <stdio.h>
int main(void) 
{
	int num,T,LastDigit,FirstDigit;
	scanf("%d",&T); // number of test cases
	for(int i=0;i<T;i++)
	   {
	       scanf("%d",&num);
	       LastDigit = num%10;
	       while(num!=0)
	       {
	         if(num<10)
	           {
	             FirstDigit=num;
	           }
               num=num/10;
	        }    
	       printf("%d\n",FirstDigit+LastDigit);
	   }
	return 0;
}
