#include<iostream.h>
#include<conio.h>
//using namespace std;
void traverse(int A[],int n)
{
 int i;
 for(i=0;i<=n-1;i++)
 cout<<A[i]<<" ";
}
void select(int A[],int pos)
{
 cout<<"Element at this position = "<<A[pos];
}
int search(int A[],int n,int item)
{
 int a=0,i;
 for(i=0;i<n;i++)
 {
  if(A[i]==item)
  {
   a=i;
  }
 }
  if(a==0)
  return -1;
  else
  return a;
}
void insert(int A[],int n,int pos,int item)
{
 int i;
 for(i=n-1;i>=pos-1;i++)
 A[i+1]=A[i];
 A[pos-1]=item;
}
void Delete(int A[],int n,int pos)
{
 int i;
 for(i=pos-1;i<n-1;i++)
 A[i]=A[i+1];
}
void sort(int A[],int n);
int main()
{
 int i,A[10],n,pos,item,ch,ret;
 char c;
 cout<<"Enter array size:";
 cin>>n;
 cout<<"\nEnter array: ";
 for(i=0;i<n;i++)
 cin>>A[i];
 do
 {
  cout<<"Choose the operation:-";
  cout<<"\n1. Traverse the array";
  cout<<"\n2. Select an element";
  cout<<"\n3. Search an element";
  cout<<"\n4. Insert an element";
  cout<<"\n5. Delete an element";
  cout<<"\n6. Sort the array\n";
  cin>>ch;
  if(ch==1)
  traverse(A,n);
  else if(ch==2)
  {
   cout<<"Enter position:";
   cin>>pos;
   select(A,pos);
  }
  else if(ch==3)
  {
   cout<<"Enter the element you want to search:";
   cin>>item;
   ret=search(A,n,item);
   if(ret==-1)
   cout<<"Sorry, element not found\n";
   else
   cout<<"Position = "<<ret;
  }
  else if(ch==4)
  {
   cout<<"Enter element u want 2 insert:";
   cin>>item;
   cout<<"Enter its position:";
   cin>>pos;
   insert(A,n,pos,item);
   n++;
   cout<<"Updated array: ";
   for(i=0;i<n;i++)
   cout<<A[i]<<" ";
   cout<<endl;
  }
  else if(ch==5)
  {
   cout<<"Enter the position of the element to be deleted:";
   cin>>pos;
   Delete(A,n,pos);
   n--;
   cout<<"Updated array: ";
   for(i=0;i<n;i++)
   cout<<A[i]<<" ";
  }
  else if(ch==6)
  sort(A,n);
  else
  cout<<"Wrong choice\n";
  cout<<"Do u want to perform more, Y or N  ?";
  cin>>c;
 
 }while(c=='y'||c=='Y');
 getch();
 return 0;
}
void sort(int A[],int n)
{
 int i,j,min,pos,t;
 for(i=0;i<n;i++)
 {
  min=A[i];
  pos=i;
  for(j=i+1;j<n;j++)
  {
   if(A[j]<A[i])
   {
    min=A[j];
    pos=j;
   }
  }
  t=A[i];
  A[i]=A[pos];
  A[pos]=t;
 }
 cout<<"Sorted Array: ";
 for(i=0;i<n;i++)
 cout<<A[i]<<" ";
 cout<<endl;
}
