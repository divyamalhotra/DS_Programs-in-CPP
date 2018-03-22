#include<iostream.h>
#include<conio.h>
struct node
{
 int data;
 node *next;
}*front=NULL,*rear=NULL;
void enqueue(int item)
{
 node *temp;
 temp=new node;
 temp->data=item;
 temp->next=NULL;
 if(front==NULL)
 {
  front=temp;
  rear=temp;
 }
 else
 {
  rear->next=temp;
  rear=temp;
 }
}
int dequeue()
{
 node *temp;
 int item;
 if(front==NULL&&rear==NULL)
 cout<<"Queue is empty!!!\n";
 else if(front==rear)
 {
  temp=front;
  item=temp->data;
  front=NULL;
  rear=NULL;
  delete temp;
  return item;
 }
 else
 {
  temp=front;
  item=temp->data;
  front=front->next;
  delete temp;
  return item;
 }
 return 0;
}
void show()
{
 node *temp;
 temp=front;
 if(temp==NULL)
 cout<<"Queue is empty!!!\n";
 while(temp!=NULL)
 {
  cout<<temp->data<<" ";
  temp=temp->next;
 }
 cout<<endl;
}
void main()
{
 int ch,item;
 char c;
 do
 {
  clrscr();
  cout<<"Choose: \n";
  cout<<"1. Insert an element in the queue\n";
  cout<<"2. Delete an element from the queue\n";
  cout<<"3. Display the queue\n";
  cin>>ch;
  if(ch==1)
  {
   cout<<"Enter the element to be inserted: ";
   cin>>item;
   enqueue(item);
   cout<<"\nUpdated queue: ";
   show();
  }
  else if(ch==2)
  {
   item=dequeue();
   if(item==0)
   cout<<"No element deleted!!!\n";
   else
   {
    cout<<"Element deleted: "<<item<<endl;
    cout<<"\nUpdated queue: ";
    show();
   }
  }
  else if(ch==3)
  show();
  else
  cout<<"Wrong choice\n";
  cout<<"Do you want to perform more ?? y or n-";
  cin>>c;
 }while(c=='y'||c=='Y');
 getch();
}


