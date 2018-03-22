#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"STACK1.H"
int *s;
int ans1(int m,int n,char op)
{
 int ans;
 if(op=='+')
 ans=n+m;
 else if(op=='-')
 ans=n-m;
 else if(op=='*')
 ans=n*m;
 else if(op=='/')
 ans=n/m;
 else if(op=='^')
 ans=pow(n,m);
 return ans;
}
int postfix_eval(char *e)
{
 strcat(e,"#");
 int i=0;
 int y,value,xi,m,n;
 char op,x;
 x=e[i++];
 while(x!='#')
 {
  if(x>='0'&&x<='9')
  {
   xi=x-'0';
   push(s,xi);
  }
  else
  {
   n=pop(s);
   m=pop(s);
   op=x;
   y=ans1(m,n,op);
   push(s,y);
  }
  x=e[i++];
 }
 value=pop(s);
 return value;
}
void main()
{
 clrscr();
 char *pfx;
 cout<<"Enter the postfix expression: ";
 gets(pfx);
 cout<<"After evaluation: "<<postfix_eval(pfx);
 getch();
}