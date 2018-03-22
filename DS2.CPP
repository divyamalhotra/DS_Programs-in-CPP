#include<iostream.h>
#include<conio.h>
int BinarySearch(int A[],int n,int item)
{
 int first,last,mid,f;
 f=0;
 first=0;
 last=n-1;
 while(first<=last)
 {
 mid=(first+last)/2;
 if(A[mid]==item)
 {
 return mid;
 f++;
 break;
 }
 else if(A[mid]>item)
 last =mid-1;
 else if(A[mid]<item)
 first =mid+1;
 }
 if(f==0)
 return -1;
 }
void main()
{
 clrscr();
 int i,n,item,A[10],ret;
 cout<<"Enter array size:";
 cin>>n;
 cout<<"Enter sorted array:";
 for(i=0;i<n;i++)
 cin>>A[i];
 cout<<"Enter the item to be searched:";
 cin>>item;
 ret=BinarySearch(A,n,item);
 if(ret==-1)
 cout<<"Element Not found\n";
 else
 cout<<"Position of element: "<<ret+1<<endl;
 getch();
 }