#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include"stack.h"
#include<string.h>
char *s;
int ICP(char x)
{
 int icp;
 if(x=='^')
 icp=6;
 else if(x=='*'||x=='/')
 icp=3;
 else if(x=='+'||x=='-')
 icp=1;
 else if(x=='(')
 icp=7;
 return icp;
}
int ISP(char x)
{
 int isp;
 if(x=='^')
 isp=5;
 else if(x=='*'||x=='/')
 isp=4;
 else if(x=='+'||x=='-')
 isp=2;
 else if(x=='(')
 isp=0;
 return isp;
}

void infix_to_postfix(char *e)
{
 int i=0;
 char x,y;
 strcat(e,"#");
 push(s,'#');
 x=e[i++];
 while(x!='#')
 {
  if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
  cout<<x;
  else if(x=='(')
  push(s,x);
  else if(x==')')
  {
   y=pop(s);
   while(y!='(')
   {
    cout<<y;
    y=pop(s);
   }
  }
  else if(x=='+'||x=='-'||x=='/'||x=='*'||x=='^')
  {
   y=pop(s);
   while(y!='#'&&ICP(x)<ISP(y))
   {
    cout<<y;
    y=pop(s);
   }
   push(s,y);
   push(s,x);
  }
  x=e[i++];
 }
 if(x=='#')
 {
  y=pop(s);
  while(y!='#')
  {
   cout<<y;
   y=pop(s);
  }
 }
}
void main()
{
 clrscr();
 char *e;
 cout<<"Enter the infix expression: ";
 gets(e);
 cout<<"Postfix: ";
 infix_to_postfix(e);
 getch();
}
