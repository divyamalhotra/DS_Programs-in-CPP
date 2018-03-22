#include<iostream.h>
#include<conio.h>
int top=-1;
int max_size;
void push(int s[],int item)
{
 if(top==max_size-1)
 cout<<"Stack is full\n";
 else
 {
  top=top+1;
  s[top]=item;
 }
}
int pop(int s[])
{
 int item;
 if(top==-1)
 return 0;
 else
 {
  item=s[top];
  top=top-1;
  return item;
 }
}
void show(int s[])
{
 if(top==-1)
 cout<<"Empty stack!!!\n";
 else
 for(int i=top;i>=0;i--)
 cout<<endl<<s[i];
}
void main()
{
 clrscr();
 int s[100],ch,item;
 char c;
 cout<<"Enter the size of the stack: ";
 cin>>max_size;
 do
 {
  clrscr();
  cout<<"Choose the operation :\n";
  cout<<"1. Display the stack\n";
  cout<<"2. Insert an element in the stack\n";
  cout<<"3. Delete an element from the stack\n";
  cin>>ch;
  if(ch==1)
  show(s);
  else if(ch==2)
  {
   cout<<"Enter the element to be inserted in the stack: ";
   cin>>item;
   push(s,item);
   cout<<"\nUpdated stack: \n";
   show(s);
  }
  else if(ch==3)
  {
   item=pop(s);
   if(item==0)
   cout<<"\nEmpty stack!!!\n";
   else
   {
    cout<<"Element deleted :"<<item<<endl;
    cout<<"\nUpdated stack: \n";
    show(s);
   }
  }
  else
  cout<<"Wrong choice\n";
  cout<<"\nDo you want to enter more ???  y or n- ";
  cin>>c;
 }while(c=='y'||c=='Y');
 getch();
}