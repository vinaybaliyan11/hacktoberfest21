
#include<stdio.h>

#include<conio.h> 
void prin(int,int);
void matrixchain(int [],int);
int m[100][100],s[100][100];
int main()
{
int i,j,p[100],n;

printf("enter the no. of matrix chian");
 scanf("%d",&n);
 printf("enter the order of chain matrix");
 for(i=0;i<=n;i++)
 scanf("%d",&p[i]);
 matrixchain(p,n);
 printf("cost of matrix \n");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 printf("\t%d",m[i][j]);
 }
 printf("\n");
 }
 printf("k- matrix\n");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 printf("\t%d",s[i][j]);
 }
 printf("\n");
 }
 prin(1,n);
 printf("\ncost of matrix chain multiplication %d", m[1][n]);
 getch();
 }
 
 
void matrixchain(int p[],int n)
{
 int i,j,k,l,q;
 for(i=1;i<=n;i++)
 {
  m[i][i]=0;
 }
 for(l=2;l<=n;l++)
 {
	for(i=1;i<=n-l+1;i++)
	 {
		 j=i+l-1;
		 m[i][j]=9999;
		 for(k=i;k<=j-1;k++)
			{
			 q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			 if(q<m[i][j])			  {
				 m[i][j]=q;
				 s[i][j]=k;
								}
			   }
	      }
 }
}
void prin(int i,int j)
{
 if(i==j)
 {
      printf("a%d",i);
       }
 else
 {
  printf("(");
  prin(i,s[i][j]);
  prin((s[i][j]+1),j);
  printf(")");

 }
}
