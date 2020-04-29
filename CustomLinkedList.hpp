#include <iostream>
#include "Node.hpp"
template <typename T>
class Linklist
{
	private:
		Node<T> *head,*tail;
		int numElements;
	public:
		Linklist()
		{
			head=NULL;
			tail=NULL;
			numElements=0;
		}
		void insertBeg()
		{
			T item;
			cout<<"enter element: ";
			cin>>item;
			++numElements;
			Node<T> *ptr;
			ptr=new Node<T>;
			ptr->data=item;
			ptr->location=1;
			ptr->display();
			if (head==NULL)
			{
				tail=ptr;
			}
			ptr->next=head;
			head=ptr;
			ptr=head->next;
			for (int i = 1; i < numElements; i++,ptr=ptr->next)
			{
				++ptr->location;
			}
			
		}
		void insertEnd()
		{
			Node<T> *ptr;
			ptr=new Node<T>;
			cout<<"enter data: ";
			cin>>ptr->data;
			++numElements;
			ptr->location=numElements;
			ptr->display();
			if(head==NULL)
			{
				head=ptr;
				tail=ptr;
			}
			else
			{
				tail->next=ptr;
				tail=ptr;
			}
		}
		void insertAfter()
		{
			Node<T> *ptr,*temp;
			int loc=0;
			ptr=new Node<T>;
			temp=new Node<T>;
			cout<<"enter data: ";
			cin>>ptr->data;
			cout<<"enter location(<="<<numElements<<"): ";
			cin>>loc;
			int poc=loc;
			ptr->location=loc;
			temp=head;
			if (loc==numElements)
			{
				insertEnd();
			}
			else
			{	
				++numElements;
				for (int i = 1; i <= numElements; i++,temp=temp->next)
				{
					if(temp->location==loc)
					{
						temp->next->location=loc+2;
						ptr->next=temp->next;
						temp->next=ptr;
						temp->next->location=i+1;
					}
					else if (temp->location > loc+1)				
					{
						ptr->location+=2;
					}
				}
			}
			ptr=head;
			for (int i = 1; i <= numElements; i++,ptr=ptr->next)
			{
				ptr->location=i;
			}
		}
		void insertAt()
		{
			Node<T> *ptr,*temp;
			ptr=new Node<T>;
			temp=new Node<T>;
			cout<<"enter data: ";
			cin>>ptr->data;
			cout<<"enter location(<="<<numElements<<"): ";
			cin>>ptr->location;
			temp=head;
			for (int i = 1; i <= numElements; i++,temp=temp->next)
			{
				if(temp->location==ptr->location)
				{
					temp->data=ptr->data;
				}
			}
			delete temp;
		}
		void deleteBeg()
		{
			Node <T> *ptr;
			ptr=new Node<T>;
			if(head==NULL)
			{
				cout<<"empty!\n";
			}
			else
			{
				ptr=head;
				cout<<"deleting:"<<ptr->data<<"\n";
				cout<<"element info: "<<ptr->data<<" number "<<ptr->location<<'\n';	
				--numElements;
				head=head->next;
				ptr=head;
				for (int i = 1; i <= numElements; i++,ptr=ptr->next)
				{
					ptr->location=i;
				}
			}
		}
		void deleteEnd()
		{
			Node <T> *ptr;
			ptr=new Node<T>;
			if(head==NULL)
			{
				cout<<"empty!\n";
			}
			else
			{
				ptr=tail;
				cout<<"deleting:"<<ptr->data<<"\n";
				cout<<"element info: "<<ptr->data<<" number "<<ptr->location<<'\n';	
				--numElements;
				ptr=head;
				for (int i = 1; i <= numElements; i++,ptr=ptr->next)
				{
					if(ptr->location==numElements)
					{
						tail=ptr;
						tail->next=NULL;
					}
				}
			}
		}
		void deleteAfter()
		{
			Node<T> *temp,*ptr;
			int loc;
			temp=new Node<T>;
			ptr=new Node<T>;
			cout<<"enter location(<"<<numElements<<"): ";
			cin>>loc;
			if (loc==numElements)
			{
				cout<<"no element after "<<ptr->location<<" for deletion\n";
			}
			else if (loc==numElements-1)
			{
				deleteEnd();
			}
			else
			{	
				temp=head;
				for (int i = 1; i <= numElements-1; i++,temp=temp->next)
				{
					if(temp->location==loc)
					{
						ptr=temp->next;
						cout<<"deleting \n";
						ptr->display();
						temp->next=ptr->next;
					}
					else if(temp->location > loc)				
					{
						ptr->location=i-1;
					}
				}
				--numElements;
				temp=head;
				for (int i = 1; i <= numElements; i++,temp=temp->next)
				{
					temp->location=i;
				}
				
			}

		}
		void traverse()
		{
			if(head==NULL)
			{
				cout<<"empty data structure\n";
			}
			else
			{
				Node <T> *ptr;
				ptr=head;
				cout<<"data elements are: \n";
				do
				{
					ptr->display();
					ptr=ptr->next;
				} while(ptr!=NULL);
				cout<<'\n';
			}
		}
		//void search(node<T> *start);   
};
