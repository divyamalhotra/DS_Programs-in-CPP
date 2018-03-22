#include<iostream.h>
#include<conio.h>
#include<string.h>
int n,front=0,rear=-1,count_adj;
char q[100];
struct node
{
 char data;
 char parent;
 char color[10];
 node* next;
};
node* list[10];
void enqueue(char item)
{
 rear++;
 q[rear]=item;
}
char dequeue()
{
 char item;
 if(front==rear+1)
 return NULL;
 item=q[front];
 front=front+1;
 return item;
}
void Insert(char item,char adj[])
{
 node *temp,*temp1;
 int i,cnt;
 i=0;
 temp1=list[i++];
 while(temp1->data!=item)
 temp1=list[i++];
 while(temp1->next!=NULL)
 temp1=temp1->next;
 for(cnt=0;cnt<count_adj;cnt++)
 {
  temp=new node;
  temp->data=adj[cnt];
  temp->next=NULL;
  temp1->next=temp;
  temp1=temp1->next;
 }
}
void BFS_VISIT(node* s)
{
 node *v,*w,*u;
 char value;
 int ch,i;
 enqueue(s->data);
 value=dequeue();
 while(value!=NULL)
 {
  i=0;
  v=list[i++];
  while(v->data!=value)
  v=list[i++];
  w=v;
  while(w->next!=NULL)
  {
   w=w->next;
   i=0;
   u=list[i++];
   while(u->data!=w->data)
   u=list[i++];
   if(strcmp(u->color,"white")==0)
   {
    strcpy(u->color,"grey");
    u->parent=v->data;
    enqueue(u->data);
   }
  }
  strcpy(v->color,"black");
  cout<<v->data<<" ";
  value=dequeue();
 }
}
void BFS()
{
 node* temp;
 int i=0;
 while(i<n)
 {
  strcpy(list[i]->color,"white");
  list[i]->parent=NULL;
  i++;
 }
 i=0;
 temp=list[i++];
 while(i<=n)
 {
  if(strcmp(temp->color,"white")==0)
  BFS_VISIT(temp);
  temp=list[i++];
 }
}
node* DFS_VISIT(node* u)
{
 strcpy(u->color,"grey");
 cout<<u->data<<" ";
 node *w=u,*v;
 int i=0;
 w=list[i++];
 while(w->data!=u->data)
 w=list[i++];
 while(w->next!=NULL)
 {
  w=w->next;
  i=0;
  v=list[i++];
  while(v->data!=w->data)
  v=list[i++];
  if(strcmp(v->color,"white")==0)
  {
   v->parent=u->data;
   v=DFS_VISIT(v);
  }
 }
 strcpy(u->color,"black");
 return u;
}
void DFS()
{
 node* temp;
 int i=0;
 while(i<n)
 {
  strcpy(list[i]->color,"white");
  list[i]->parent=NULL;
  i++;
 }
 i=0;
 temp=list[i++];
 while(i<=n)
 {
  if(strcmp(temp->color,"white")==0)
  temp=DFS_VISIT(temp);
  temp=list[i++];
 }
}
void main()
{
 clrscr();
 char item,c,adj[10];
 node* temp;
 int i,j,ch;
 for(i=0;i<10;i++)
 list[i]=NULL;
 cout<<"\nEnter no. of vertices: ";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cout<<"Enter value of vertex: ";
  cin>>item;
  temp=new node;
  temp->data=item;
  temp->next=NULL;
  list[i]=temp;
  cout<<"Enter the no. of adjacents you want the node to have: ";
  cin>>count_adj;
  cout<<"Enter the nodes you want to be its adjacent: ";
  for(j=0;j<count_adj;j++)
  cin>>adj[j];
  Insert(item,adj);
 }
 do
 {
  clrscr();
  cout<<"\nChoose: ";
  cout<<"\n1. BFS of graph";
  cout<<"\n2. DFS of graph";
  cin>>ch;
  if(ch==1)
  BFS();
  else if(ch==2)
  DFS();
  else
  cout<<"\nWrong choice!!!";
  cout<<"\nDo you want to perform another search? y or n-";
  cin>>c;
 }while(c=='y');
 getch();
}





