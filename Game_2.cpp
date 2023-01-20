#include <iostream>
#include <fstream>  
using namespace std;

class node
{
	private:
	string data;
	node* next;
	node* pre;
	node *head=NULL;
	node *ptr;
	
	public:
	void InsertNode(string value)
	{
		node* temp=new node();
		temp->data=value;
		temp->pre=NULL;
		temp->next=NULL;
		
		if(head==NULL)
		{
			head=temp;
			ptr=head;
		}
		
		else
		{
			ptr->next=temp;
			temp->pre=ptr;
			ptr=temp;	
		}
	}
	
	void Circular()
	{
		ptr->next=head;
		head->pre=ptr;
	}
	
	void FindNode(int num)
	{
		num=num/2;
		ptr=head;
		int pivot=1;
		while(pivot<num)
		{
			pivot++;
			ptr=ptr->next;
		}
		
		cout<<"\nMID VALUE : "<<num;
		cout<<"\nSTARTING VALUE : "<<ptr->data;

	}
	
	void RemoveNode(int num)
	{
		cout<<"\nVALUE TO REMOVE VALUE : ";
		for (int i=1 ; i<=num ; i++)
		{
			cout<<ptr->data<<" -> ";
			ptr=ptr->next;
		}
		cout<<ptr->data;
		cout<<"\nCLOCKWISE : "<<num<<endl<<endl;
		
		if(ptr!=head)
		{
			node *temp1 = ptr->pre;
		node *temp2= ptr->next;
		
		temp1->next=temp2;
		temp2->pre=temp1;
		}
		
		else if(ptr==head)
		{
			node*temp=head;
			head=head->next;
			ptr=ptr->pre;
			
			ptr->next=head;
			head->pre=ptr;
		}
		
		
	}
	


	bool isEmpty()
	{
		if(head->next==head)
		{
			head=NULL;
			return true;
		}
		
		
		else return false;
	}
	
	void show()
	{
		ptr=head;
		do
		{
			cout<<"\t"<<ptr->data;
			ptr=ptr->next;
		}
		while(ptr!=head);		
	}
	
	int size()
	{
		int size=0;
		ptr=head;
		
		cout<<endl;
		do
		{
			ptr=ptr->next;
			size++;
		}
		while(ptr!=head);
		return size;
	}

};





int main()
{
	node FirstList,SecondList;
	string s;
	int num=0;
	bool flag;
	fstream file("name.txt");
	cout<<"\tDouble Circular Children game\n";
	while(!file.eof())
	{
		flag=false;
		getline(file,s);
		num++;
		
		for(int i=2;i<num;i++)
		{
			if(num%i==0)
			{
				flag=true;
				break;
			}
		}
		
		if(!flag)
		{
		    FirstList.InsertNode(s);
		}
		
		else
		{
			SecondList.InsertNode(s);
		}
	}
		
	FirstList.Circular();
	SecondList.Circular();
	cout<<"\n\nINITIAL LISTS :\n\n";
	cout<<"Prime List : ";
	FirstList.show();
	int size1=FirstList.size();
	cout<<"Prime Size : "<<size1;
	cout<<endl<<endl;
	cout<<"\nNon-Prime List : ";
	SecondList.show();
	int size2=SecondList.size();
	cout<<"Second Size : "<<size2;
	
	
	while(!SecondList.isEmpty())
	{
		cout<<endl;
		SecondList.FindNode(size2);
		SecondList.RemoveNode(size1);
		
		cout<<"First List : ";
		FirstList.show();
		cout<<"\nSecond List : ";
		SecondList.show();
		cout<<"\n-----------------------------------------------";
		size2=SecondList.size();
		system("pause");
	}	
	
}

