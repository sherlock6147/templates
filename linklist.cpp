#include <iostream>
#include "CustomLinkedList.hpp"
int main(){
    int choice=0;
    Linklist <int> sll;
    do
    {
        cout<<"1 to insert from beggining\n";
		cout<<"2 to insert at end\n";
		cout<<"3 to insert after\n";
		cout<<"4 to insert at\n";
		cout<<"5 to delete from beggining\n";
		cout<<"6 to delete from end\n";
		cout<<"7 to delete after\n";
		cout<<"8 to traverse\n";
		//cout<<"4 to search\n";
		cout<<"0 to exit\n";
		cin>>choice;
		switch(choice)
        {
			case 0:
            {
                break;
			}
            case 1:
            {
			    sll.insertBeg();
                break;
			}
            case 2:
            {
			    sll.insertEnd();
                break;
			}
            case 3:
            {
			    sll.insertAfter();
                break;
			}
            case 4:
            {
			    sll.insertAt();
                break;
			}
			case 5:
            {
				sll.deleteBeg();
                break;
			}
            case 6:
            {
                sll.deleteEnd();
                break;
            }
            case 7:
            {
                sll.deleteAfter();
                break;
            }
            case 8:
            {
                sll.traverse();
                break;
            }
			default: cout<<"try again\n";
		}
    }while(choice!=0);
    return 0;
}