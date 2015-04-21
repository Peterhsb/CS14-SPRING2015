#ifndef LAB2_H

#define LAB2_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

template<class Type>
class List
{
 public:
    List():head(0), tail(0){}; 
    ~List();
    void push(Type);
    void pop_front();
    void display() const; 
    void print() const;
    int size() const; 
    List <Type> elementSwap(int pos);
 private:
    struct Node
    {
        Type data; 
        Node *next;
        Node(Type data) : data(data), next(0) {}
    };
    Node *head;
    Node *tail;
};

template<class Type>
List<Type>::~List()
{
    while(head != 0)
    {
        pop_front();
    }
}

template<class Type>
void List<Type>::push(Type val)
{
    Node *temp = new Node(val);
    if(!head)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp; 
    temp = tail;
    tail = tail->next;
}

template<class Type>
void List<Type>::pop_front()
{
    if(head == 0)
    {
        return;
    }
    Node *temp = head; 
    head = head->next; 
    delete temp; 
    if(head == 0)
    {
        tail = 0;
    }
}

template<class Type>
void List<Type>::display() const
{
    Node *currt;
    for(currt = head; currt != 0; currt = currt->next)
    {
        std::cout << currt->data;
        if(currt->next != 0)
        {
            std::cout << ' ';
        }
    }
    cout << endl;
}

template<class Type>
void List<Type>::print() const
{
    Node *currt;
    for(currt = head; currt != 0; currt = currt->next)
    {
        cout << currt->data;
        if(currt->next != 0)
        {
            cout << ' ';
        }
    }
    cout << endl;
}
template<class Type>
int List<Type>::size() const
{
	int s = 0;
	Node *currt;
	for(currt = head; currt != 0; currt = currt->next)
	{
		s++;
	}
	return s;
}


template<class Type>
List<Type> List<Type>::elementSwap(int pos)
{
    if(size() <= 1)
    {
        cout << "The list is too small for swap to be used. " << endl;
        exit(0);
    }
    if(pos > size() - 2)
    {
        cout << "Invalid position. " << endl;
        exit(0);
    }
    Node *start;
    for(start = head; pos > 1; start = start->next)
    { pos--; }
    if(size() == 2)
    {
        Node *temp = head; 
        head = head->next; 
        head->next = temp;
        temp->next = 0;
        return *this;
    }
    Node *temp1 = start->next;
    Node *temp2 = temp1->next;
    
    start->next = temp2; 
    temp1->next = temp2->next;
    temp2->next = temp1;
    return *this;
}

#endif