#include<iostream.h>
#include<conio.h>
//using namespace std;
struct NODE
{
 int data;
 NODE *next;
}*list;
//NODE *list=NULL;
void Traverse_CLL()
{
 NODE *temp;
 temp=list;
 while(temp->next!=list)
 {
  cout<<temp->data<<" ";
  temp=temp->next;
 }
 cout<<temp->data<<endl;
}
void InsertBefore_CLL(int value,int key)
{
 NODE *temp,*temp1,*prev;
 temp=new NODE;
 temp->data=value;
 temp->next=NULL;
 temp1=list;
 prev=list;
 while(prev->next!=list)
 prev=prev->next;
 while(temp1->data!=key&&temp1->next!=list)
 {
  prev=temp1;
  temp1=temp1->next;
 }
 if(temp1->data==key)
 {
  temp->next=temp1;
  prev->next=temp;
  if(temp1==list)
  list=temp;
 }
 else
 cout<<"Key not found\n";
 cout<<"Updated list: ";
 Traverse_CLL();
}
void InsertAfter_CLL(int value,int key)
{
 NODE *temp,*temp1;
 temp=new NODE;
 temp->data=value;
 temp->next=NULL;
 temp1=list;
 while(temp1->data!=key&&temp1->next!=list)
 temp1=temp1->next;
 if(temp1->data==key)
 {
  temp->next=temp1->next;
  temp1->next=temp;
 }
 else
 cout<<"Key not found\n";
 cout<<"Updated list: ";
 Traverse_CLL();
}
void Delete_CLL(int key)
{
 NODE *temp,*previous;
 temp=list;
 previous=list;
 while(previous->next!=list)
 previous=previous->next;
 while(temp->data!=key&&temp->next!=NULL)
 {
  previous=temp;
  temp=temp->next;
 }
 if(temp->data==key)
 {
  previous->next=temp->next;
  if(temp==list)
  list=list->next;
  delete temp;
 }
 else
 cout<<"Key not found\n";
 cout<<"Updated list: ";
 Traverse_CLL();
}
int main()
{
 int value,key,choice,inschoice;
 char c,c1;
 list=new NODE;
 cout<<"Enter value in first node";
 cin>>value;
 list->data=value;
 key=value;
 list->next=list;
 cout<<"Do you want to make new node? y or n-";
 cin>>c;
 while(c=='y'||c=='Y')
 {
  cout<<"Enter value:";
  cin>>value;
  InsertAfter_CLL(value,key);
  key=value;
  cout<<"Do you want to enter new node? y or n-";
  cin>>c;
 }
 do
 {
  clrscr();
  cout<<"Choose the operation: \n";
  cout<<"1. Traverse the list\n";
  cout<<"2. Insert new element in the list\n";
  cout<<"3. Delete an element from the list\n";
  cin>>choice;
  if(choice==1)
  Traverse_CLL();
  else if(choice==2)
  {
   cout<<"Select from the following: \n";
   cout<<"1. Insert element before a particular node\n";
   cout<<"2. Insert element after a particular node\n";
   cin>>inschoice;
   if(inschoice==1)
   {
    cout<<"Enter the key before which you want to insert the element: ";
    cin>>key;
    cout<<"Enter the element you want to insert: ";
    cin>>value;
    InsertBefore_CLL(value,key);
   }
   else if(inschoice==2)
   {
    cout<<"Enter the key after which you want to insert the element: ";
    cin>>key;
    cout<<"Enter the element that you want to insert: ";
    cin>>value;
    InsertAfter_CLL(value,key);
   }
   else
   cout<<"Wrong choice\n";
  }
  else if(choice==3)
  {
   cout<<"Enter the element you want to delete: ";
   cin>>value;
   Delete_CLL(value);
  }
  else
  cout<<"Wrong choice\n";
  cout<<"Do you want to perform more? y or n-";
  cin>>c1;
  clrscr();
 }while(c1=='y'||c1=='Y');
 getch();
 return 0;
}
