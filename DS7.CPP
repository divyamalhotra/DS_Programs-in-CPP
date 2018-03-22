#include<iostream.h>
#include<conio.h>
//using namespace std;
struct NODE
{ 
 int data;
 NODE *next;
};
NODE *list;
void Traverse_SLL(NODE *list)
{
 NODE *temp;
 temp=list;
 while(temp!=NULL)
{
 cout<<temp->data<<" ";
 temp=temp->next;
 }
}
void InsertFirst_SLL(NODE *list,int value)
{
 NODE *temp;
 temp=new NODE;
 temp->data=value;
 temp->next=list;
 list=temp;
 cout<<"Updated list: ";
 Traverse_SLL(list);
}
void InsertAfter_SLL(NODE *list,int value,int key)
{
 NODE *temp,*temp1;
 temp=new NODE;
 temp->data=value;
 temp->next=NULL;
 temp1=list;
 while(temp1->data!=key&&temp1->next!=NULL)
 temp1=temp1->next;
 if(temp1->data==key)
 {
   temp->next=temp1->next;
   temp1->next=temp;
 }
 else
 cout<<"Key not found\n";
 cout<<"Updated list: ";
 Traverse_SLL(list);
}
void InsertBefore_SLL(NODE *list,int value,int key)
{
 NODE *temp,*temp1,*previous;
 temp=new NODE;
 temp->data=value;
 temp->next=NULL;
 temp1=list;
 if(temp1->data==key)
  {
   temp->next=list;
   list=temp;
  }
  else
  {
   while(temp1->data!=key&&temp1->next!=NULL)
   {
    previous=temp1;
    temp1=temp1->next;
   }
   if(temp1->data==key)
    {
     temp->next=temp1;
     previous->next=temp;
    }
    else
    cout<<"Key not found\n";
   }
   cout<<"Updated list: ";
   Traverse_SLL(list);
 }
void Delete_SLL(NODE *list,int key)
{
 NODE *temp,*previous;
 temp=list;
 if(temp->data==key)
 {
  list=list->next;
  delete temp;
 }
 else
 {
  while(temp->data!=key&&temp->next!=NULL)
  {
   previous=temp;
   temp=temp->next;
  }
  if(temp->data==key)
  {
   previous->next=temp->next;
   delete temp;
  }
  else
  cout<<"Key not found\n";
 }
 cout<<"Updated list: ";
 Traverse_SLL(list);
}
void Reverse_SLL(NODE *list)
{
 NODE *currnode,*prevnode,*nextnode;
 currnode=list;
 prevnode=NULL;
 while(currnode!=NULL)
 {
  nextnode=currnode->next;
  currnode->next=prevnode;
  prevnode=currnode;
  currnode=nextnode;
 }
 list=prevnode;
 cout<<"Updated list: ";
 Traverse_SLL(list);
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
 list->next=NULL;
 cout<<"Do you want to make new node? y or n-";
 cin>>c;
 while(c=='y'||c=='Y')
 {
  cout<<"Enter value:";
  cin>>value;
  InsertAfter_SLL(list,value,key);
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
  cout<<"4. Reverse the list\n";
  cin>>choice;
  if(choice==1)
  Traverse_SLL(list);
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
    InsertBefore_SLL(list,value,key);
   }
   else if(inschoice==2)
   {
    cout<<"Enter the key after which you want to insert the element: ";
    cin>>key;
    cout<<"Enter the element that you want to insert: ";
    cin>>value;
    InsertAfter_SLL(list,value,key);
   }
   else
   cout<<"Wrong choice\n";
  }
  else if(choice==3)
  {
   cout<<"Enter the element you want to delete: ";
   cin>>value;
   Delete_SLL(list,value);
  }
  else if(choice==4)
  Reverse_SLL(list);
  else
  cout<<"Wrong choice\n";
  cout<<"Do you want to perform more? y or n-";
  cin>>c1;
  clrscr();
 }while(c1=='y'||c1=='Y');
 getch();
 return 0;
}
