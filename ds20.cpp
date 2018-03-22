#include<iostream>
#include<conio.h>
using namespace std;
void Insertion_sort(int A[],int n)
{
	int key,i;
	for(int j=1;j<n;j++)
	{
	 	key=A[j];
		 i=j-1;
		 while(i>=0&&A[i]>key)
		 {
		 	A[i+1]=A[i];
		 	i--;
	     }	
		A[i+1]=key;	 
	}
}
void swap(int&x,int&y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
void Bubble_sort(int A[],int n)
{
	int i=1;
	bool swapped;
	do
	{
		swapped=false;
		for(int j=0;j<n-i;j++)
		{
			if(A[j+1]<A[j])
			{
				swap(A[j+1],A[j]);
	            swapped=true;
			}
		}
		i++;
	}while(swapped);
}
void Merge(int A[],int s1,int e1,int s2,int e2)
{
	int i=0;
	int result[e2-s1+1];
	int finalstart=s1,finalend=e2;
	while(s1<=e1&&s2<=e2)
	{
		if(A[s1]<A[s2])
		{
			result[i]=A[s1];
			i++;
			s1++;
		}
		else
		{
			result[i]=A[s2];
			i++;
			s2++;
		}
	}
	while(s1<=e1)
	{
		result[i]=A[s1];
		i++;
		s1++;
	}
	while(s2<=e2)
	{
		result[i]=A[s2];
		i++;
		s2++;
	}
	int k=0;
	for(int j=finalstart;j<=finalend;j++)
	{
		A[j]=result[k];
		k++;
	}
}
void Merge_sort(int A[],int first,int last)
{
	int mid;
	if(first<last)
	{
		mid=(first+last)/2;
		Merge_sort(A,first,mid);
		Merge_sort(A,mid+1,last);
		Merge(A,first,mid,mid+1,last);
	}
}
int Pivot_list(int A[],int first,int last)
{
	int pivot_value=A[first];
	int pivot_point=first;
	for(int i=first+1;i<=last;i++)
	{
		if(A[i]<pivot_value)
		{
			pivot_point++;
			swap(A[pivot_point],A[i]);
		}
	}
	swap(A[first],A[pivot_point]);
	return (pivot_point);
}
void Quick_sort(int A[],int first,int last)
{
	int pivot;
	if(first<last)
	{
		pivot=Pivot_list(A,first,last);
		Quick_sort(A,first,pivot-1);
		Quick_sort(A,pivot+1,last);
	}
}
void Max_heapify(int A[],int i,int hs)
{
	int largest;
	int l=2*i+1;
	int r=2*i+2;
	if(l<hs&&A[l]>A[i])
	largest=l;
	else largest=i;
	if(r<hs&&A[r]>A[largest])
	largest=r;
	if(largest!=i)
	{
		swap(A[i],A[largest]);
		Max_heapify(A,largest,hs);
	}
}
void Build_MaxHeap(int A[],int hs)
{
	for(int i=hs/2;i>=0;i--)
	{
		Max_heapify(A,i,hs);
	}
}
void Heap_sort(int A[],int n)
{
	Build_MaxHeap(A,n);
	int hs=n;
	for(int i=n-1;i>0;i--)
	{
		swap(A[0],A[i]);
		hs--;
		Max_heapify(A,0,hs);
	}
}
void show(int A[],int n)
{
	cout<<"\nSorted Array: ";
	for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
}
int main()
{
	int ch,size;
	int A[10];
	char c;
	do
	{
		cout<<"Enter the size of array: ";
		cin>>size;
		cout<<"Enter array: ";
		for(int i=0;i<size;i++)
		cin>>A[i];
		cout<<"Select the type of sorting you want to perform: \n";
		cout<<"1. Insertion Sort\n";
		cout<<"2. Bubble Sort\n";
		cout<<"3. Merge Sort\n";
		cout<<"4. Quick Sort\n";
		cout<<"5. Heap Sort\n";
		cin>>ch;
		if(ch==1)
		{
			Insertion_sort(A,size);
		    show(A,size);
		}
		else if(ch==2)
		{
			Bubble_sort(A,size);
			show(A,size);
		}
		else if(ch==3)
		{
			Merge_sort(A,0,size-1);
			show(A,size);
		}
		else if(ch==4)
		{
			Quick_sort(A,0,size-1);
			show(A,size);
		}
		else if(ch==5)
		{
			Heap_sort(A,size);
			show(A,size);
		}
		else
		cout<<"\nWrong choice!!!";
		cout<<"\nDo you want to perform more? y or n-";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
