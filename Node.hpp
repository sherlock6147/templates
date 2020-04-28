#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
class Node
{
public:
    Node<T> *next=NULL;
    T data;
    int location;
    void display()
    {
        cout<<"element info: "<<data<<" location :"<<location<<'\n';
    }
};