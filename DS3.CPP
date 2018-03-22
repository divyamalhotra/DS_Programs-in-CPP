#include<iostream.h>
#include<conio.h>
int* Merge(int A[],int B[],int n,int m)
{
static  int C[50];
 int k,i,j;
 i=j=k=0;
 while(i<n&&j<m)
 {
  if(A[i]<B[j])
  {
   C[k]=A[i];
   i++;
   k++;
  }
  else
  {
  C[k]=B[j];
  j++;
  k++;
  }
 }
 while(j<m)
 {
  C[k]=B[j];
  j++;
  k++;
 }
 while(i<n)
 {
  C[k]=A[i];
  k++;
  i++;
 }
 return C;
 }
 void main()
 {
 clrscr();
 int i,j,n,m,A[20],B[20],*C;
 cout<<"Enter 1st array size:";
 cin>>n;
 cout<<"Enter 2nd array size:";
 cin>>m;
 cout<<"Enter 1st array:";
 for(i=0;i<n;i++)
 cin>>A[i];
 cout<<"Enter 2nd array:";
 for(j=0;j<m;j++)
 cin>>B[j];
 /*for(i=0;i<n;i++)
 cout<<A[i]<<" ";
 for(i=0;i<m;i++)
 cout<<B[i]<<" ";*/
 C=Merge(A,B,n,m);
 cout<<"Resultant array:";
 for(i=0;i<n+m;i++)
 cout<<*(C+i)<<" ";
 getch();
 }