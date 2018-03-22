#include<iostream.h>
#include<conio.h>
int** Transpose(int A[20][20],int n,int m)
{
 int i,j;
 int **T;
 T=new int*[m];
 for(i=0;i<m;i++)
 {
  T[i]=new int[n];
  for(j=0;j<n;j++)
  T[i][j]=A[j][i];
 }

 return T;
}
int** Add(int A[20][20],int B[20][20],int n,int m)
{
 int i,j;
 int **C;
 C=new int*[n];
 for(i=0;i<n;i++)
 {
  C[i]=new int[m];
  for(j=0;j<m;j++)
  C[i][j]=A[i][j]+B[i][j];
 }
 return C;
}
int** Sub(int A[20][20],int B[20][20],int n,int m)
{
 int i,j;
 int **C;
 C=new int*[n];
 for(i=0;i<n;i++)
 {
  C[i]=new int[m];
  for(j=0;j<m;j++)
  C[i][j]=A[i][j]-B[i][j];
 }
 return C;
}
int** Multi(int A[20][20],int B[20][20],int l,int n,int m)
{
 int i,j,k;
 int **C;
 C=new int*[l];
 for(i=0;i<l;i++)
 {
  C[i]=new int[m];
  for(j=0;j<n;j++)
  {
   C[i][j]=0;
   for(k=0;k<m;k++)
   C[i][j]+=A[i][k]*B[k][j];
  }
 }
 return C;
}
void main()
{
 int A[20][20],B[20][20],i,j,k,n,m,l,ch,**C1,**T1;
 char c;
 do
 {
  cout<<"Select the operation:\n";
  cout<<"1. Add 2 matrices\n";
  cout<<"2. Subtract 2 matrices\n";
  cout<<"3. Multiply 2 matrices\n";
  cout<<"4. Transpose a matrix\n";
  cin>>ch;
  if(ch==1)
  {
   cout<<"Enter size of matrix\n Rows:";
   cin>>n;
   cout<<"Columns:";
   cin>>m;
   cout<<"Enter 1st matrix:";
   for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   cin>>A[i][j];
   cout<<"Enter 2nd matrix:";
   for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   cin>>B[i][j];
   C1=Add(A,B,n,m);
   cout<<"Sum:";
   for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    cout<<C1[i][j]<<" ";
    cout<<endl;
   }
  }
  else if(ch==2)
  {
   cout<<"Enter size of matrix\n Rows:";
   cin>>n;
   cout<<"Columns:";
   cin>>m;
   cout<<"Enter 1st matrix:";
   for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   cin>>A[i][j];
   cout<<"Enter 2nd matrix:";
   for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   cin>>B[i][j];
   C1=Sub(A,B,n,m);
   cout<<"Resultant array:";
   for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    cout<<C1[i][j]<<" ";
    cout<<endl;
   }
  }
  else if(ch==3)
  {
   cout<<"Enter no. of rows of 1st matrix:";
   cin>>l;
   cout<<"Enter no. of columns of 1st matrix:";
   cin>>m;
   cout<<"Enter no. of columns of 2nd matrix:";
   cin>>n;
   cout<<"Enter 1st matrix:";
   for(i=0;i<l;i++)
   for(j=0;j<m;j++)
   cin>>A[i][j];
   cout<<"Enter 2nd matrix:";
   for(i=0;i<m;i++)
   for(j=0;j<n;j++)
   cin>>B[i][j];
   C1=Multi(A,B,l,n,m);
   cout<<"Product :";
   for(i=0;i<l;i++)
   {
    for(j=0;j<n;j++)
    cout<<C1[i][j]<<" ";
    cout<<endl;
   }
  }
  else if(ch==4)
  {
   cout<<"Enter no. of rows:";
   cin>>n;
   cout<<"Enter no. of columns:";
   cin>>m;
   cout<<"Enter matrix:";
   for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    cin>>A[i][j];
   }
   T1=Transpose(A,n,m);
   cout<<"Transpose:\n";
   for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
    cout<<T1[i][j]<<" ";
    cout<<endl;
   }
  }
  else
  cout<<"Wrong choice\n";
  cout<<"Do you want to enter more? Y or N\n";
  cin>>c;
  clrscr();
 }
 while(c=='y'||c=='Y');
 getch();
}









