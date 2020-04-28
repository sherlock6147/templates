#include <iostream>
#include "Node.hpp"
template <typename T>
class Linklist
{
	private:
		Node<T> *head,*tail;
		int numElements;
	public:
		singleLinklist()
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
			ptr=new Node<T>;
			temp=new Node<T>;
			cout<<"enter data: ";
			cin>>ptr->data;
			cout<<"enter location(<="<<numElements+1<<"): ";
			cin>>ptr->location;
			temp=head;
			++numElements;
			for (int i = 1; i <= numElements; i++,temp=temp->next)
			{
				if(temp->location+1==ptr->location-1)
				{
					ptr->next=temp->next;
					temp->next=ptr;
				}
				else if (temp->location+1 > ptr->location)				
				{
					++ptr->location;
				}
			}
		}
		void insertAt()
		{
			Node<T> *ptr,*temp;
			ptr=new Node<T>;
			temp=new Node<T>;
			cout<<"enter data: ";
			cin>>ptr->data;
			cout<<"enter location(<="<<numElements+1<<"): ";
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
		//void delete_at(node<T> *start);
		//void delete_after(node<T> *start);
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
