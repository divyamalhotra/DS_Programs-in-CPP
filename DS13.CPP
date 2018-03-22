#include<iostream.h>
#include<conio.h>
int q[100],front=0,rear=-1,max_size;
void enqueue(int item)
{
 if(rear==max_size-1)
 cout<<"\nQueue is full\n";
 else
 {
  rear++;
  q[rear]=item;
 }
}
void dequeue()
{
 if(front==rear+1)
 cout<<"\nQueue is empty\n";
 else
 {
  int item;
  item=q[front];
  front=front+1;
  cout<<"Element deleted: "<<item<<endl;
 }
}
void display()
{
 if(rear==-1)
 cout<<"\nQueue is empty!!!\n";
 else
 {
  for(int i=front;i<=rear;i++)
  cout<<q[i]<<" ";
  cout<<endl;
 }
}
void main()
{
 clrscr();
 int ch,item;
 char c;
 cout<<"Enter max size of queue: ";
 cin>>max_size;
 do
 {
  cout<<"\nChoose: ";
  cout<<"\n1. Insert an element in the queue";
  cout<<"\n2. Delete an element from the queue";
  cout<<"\n3. Display the queue";
  cin>>ch;
  if(ch==1)
  {
   cout<<"Enter the element you want to insert: ";
   cin>>item;
   enqueue(item);
   cout<<"\nUpdated queue: \n";
   display();
  }
  else if(ch==2)
  {
   dequeue();
   cout<<"\nUpdated queue: \n";
   display();
  }
  else if(ch==3)
  display();
  else
  cout<<"Wrong choice\n";
  cout<<"Do you want to perform more?? y or n-";
  cin>>c;
  clrscr();
 }while(c=='y'||c=='Y');
 getch();
}