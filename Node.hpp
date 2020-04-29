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
    void get_data()
    {
        cout<<"enter data: ";
        cin>>data;
    }
    void disp_data()
    {
        cout<<data;
    }
    void display()
    {
        cout<<"element info: ";
        disp_data();
        cout<<" location :"<<location<<'\n';
    }
};
/*
template <typename T=char[]>
class Node
{
public:
    T data;
    Node<T> *next=NULL;
    int location;
    void get_data()
    {
        cout<<"enter data: ";
        cin.getline(data,200,'\n');
    }
    void disp_data()
    {
        cout<<data;
    }
    void display()
    {
        cout<<"element info: ";
        disp_data();
        cout<<" location :"<<location<<'\n';
    }
}; */