#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int A[10],B[10],C[10],D[10],R[20],P[20],i,j,k,n,m;
 cout<<"Enter no of terms in 1st equation:";
 cin>>n;
 cout<<"Enter no of terms in 2nd equation:";
 cin>>m;
 cout<<"Enter coefficients and exponent parts of 1st equation\n";
 for(i=0;i<n;i++)
 {
  cin>>A[i];
  cin>>B[i];
 }
 cout<<"Enter coefficients and exponent parts of 2nd equation\n";
 for(j=0;j<m;j++)
 {
  cin>>C[j];
  cin>>D[j];
 }
 i=j=k=0;
 while(i<n&&j<m)
 {
  if(B[i]==D[j])
  {
   R[k]=A[i]+C[j];
   P[k]=B[i];
   i++;
   j++;
   k++;
  }
  else if(B[i]>D[j])
  {
   R[k]=A[i];
   P[k]=B[i];
   i++;
   k++;
  }
  else
  {
   R[k]=C[j];
   P[k]=D[j];
   j++;
   k++;
  }
 }
 while(i<n)
 {
  R[k]=A[i];
  P[k]=B[i];
  i++;
  k++;
 }
 while(j<m)
 {
  R[k]=C[j];
  P[k]=D[j];
  j++;
  k++;
 }
 cout<<"Sum : ";
 for(i=0;i<k;i++)
 {
  cout<<R[i]<<"x^"<<P[i];
  if(i<k-1)
  cout<<"+";
  }
 getch();
 }
