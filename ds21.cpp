#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ln,c;
	int ch;
	ifstream in;
	do
	{
		in.open("divya.txt");
		cout<<"The contents of the file are:\n";
		in.get(ln);
		while(in.eof()==0)
		{
			cout<<ln;
			in.get(ln);
		}
		in.close();
		cout<<"\nChoose: \n";
		cout<<"1. Delete a line from the file\n";
		cout<<"2. Find the no. of lines in the file\n";
		cout<<"3. Append the content of file at the end of another file\n";
		cout<<"4. Copy the file into another file\n";
		cin>>ch;
		if(ch==1)
		{
			int n,c=0;
			cout<<"Enter the line no. u want 2 delete: ";
			cin>>n;
			ofstream temp;
			temp.open("div");
			in.open("divya.txt");
			//in.seekg(0);
			in.get(ln);
		    while(c!=(n-1)&&in.eof()==0)
			{
				temp<<ln;
				if(ln=='.'||ln=='!'||ln=='?')
				c++;
				in.get(ln);
			}
			while(in.eof()==0)
			{
			   if(ln=='.'||ln=='!'||ln=='?')
			   break;
			   in.get(ln);
		    }
			in.get(ln);
			while(in.eof()==0)
			{
				temp<<ln;
				in.get(ln);
			}
			temp.close();
			in.close();
			cout<<"\nUpdated contents of the file: \n";
			ifstream in;
			in.open("div");
			in.get(ln);
			while(in.eof()==0)
			{
				cout<<ln;
				in.get(ln);
			}
			in.close();
		}
		else if(ch==2)
		{
			int c=0;
			in.open("divya.txt");
			in.get(ln);
			while(in.eof()==0)
			{
			   if(ln=='.'||ln=='!'||ln=='?')
			   c++;
			   in.get(ln);
		    }
		    cout<<"\nThe number of lines are: "<<c<<endl;
		    in.close();
		}
		else if(ch==3)
		{
			cout<<"\nThe original contents of the new file are:\n";
			in.open("saema");
			in.get(ln);
			while(in.eof()==0)
			{
				cout<<ln;
				in.get(ln);
			}
			in.close();
			ofstream out;
			out.open("saema",ios::app);
			out<<'\n';
			in.open("divya");
			in.get(ln);
			while(in.eof()==0)
			{
				out<<ln;
				in.get(ln);
			}
			in.close();
			out.close();
			ifstream fin;
			cout<<"\n\nThe updated contents of the new file are:\n";
			fin.open("saema");
			fin.get(ln);
			while(fin.eof()==0)
			{
				cout<<ln;
				fin.get(ln);
			}
			fin.close();
		}
		else if(ch==4)
		{
			char name[20];
			cout<<"\nEnter the name of the new file\n";
			cin>>name;
			ofstream fout;
			fout.open(name);
			in.open("divya.txt");
			in.get(ln);
			while(in.eof()==0)
			{
				fout<<ln;
				in.get(ln);
			}
			in.close();
			fout.close();
			cout<<"The contents of "<<name<<" file are:\n";
			in.open(name);
			in.get(ln);
			while(in.eof()==0)
			{
				cout<<ln;
				in.get(ln);
			}
			in.close();
		}
		else
	    cout<<"\nYou have entered the wrong choice!!!\n";
	    cout<<"\nDo you want to perform again?\n";
	    cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
