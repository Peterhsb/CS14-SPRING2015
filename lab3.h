#ifndef LAB3_H

#define LAB3_H

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

template<class T>
class TwoStacksFixed 
{
 private: 
	T *stacks; 
	int length; 
	int maxTop;
	int stackTop1; 
	int stackTop2; 
 public:	
	TwoStacksFixed(int size, int maxtop)
	 :length(size), maxTop(maxtop), stackTop1(0), stackTop2(size - 1)
	{
		stacks = new T[size];
	}
	
	~TwoStacksFixed()
	{
	    delete[] stacks;
	}
	
	void pushStack1(T value)
	{
	   if(isFullStack1())
	   {
	        cout << "Error: The stack is alread full.";
	        return;
	   }
	   if(length == 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return;
	   }
	    stacks[stackTop1] = value;
	    stackTop1++;
	    display();
	}
	
	void pushStack2(T value)
	{
	    if(isFullStack2())
	    {
	        cout << "Error: The stack is alread full." << endl;
	        return;
	    }
	    if(length == 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return;
	   }
	    stacks[stackTop2] = value;
	    stackTop2--; 
	    display();
	}
	
	T popStack1()
	{
	    if(isFullStack1())
	    {
	        stackTop1--;
	    }
	    if(isEmptyStack1())
	    {
	        cout << "Error: nothing to pop" << endl;
	        exit(0);
	    }
	    T temp = stacks[stackTop1];
	    stackTop1--;
	    return temp;
	}
	
	T popStack2()
	{
	    if(isFullStack2())
	    {
	        stackTop2++;
	    }
	    if(isEmptyStack2())
	    {
	        cout << "Error: nothing to pop" << endl;
	        exit(0);
	    }
	    T temp = stacks[stackTop2];
	    stackTop2++;
	    return temp;
	}
	
	bool isFullStack1()
	{
	    if(stackTop1 > maxTop)
	    {
	        return true;
	    }
	    return false;
	}
	
	bool isFullStack2()
	{
	    if(stackTop2 == maxTop)
	    {
	        return true;
	    }
	    return false;
	}
	bool isEmptyStack1()
	{
	    if(stackTop1 < 0)
	    {
	        return true;
	    }
	    return false;
	}
	
	bool isEmptyStack2()
	{
	    if(stackTop2 >= (length))
	    {
	        return true;
	    }
	    return false;
	}
	
	void display()
	{
	    for(int i = 0; i < length; i++)
	    {
	        if(i < stackTop1)
	        {
	            cout << stacks[i] << ' ';
	        }
	        else if(i > stackTop2)
	        {
	            cout << stacks[i] << ' ';
	        }
	        else
	        {
	            cout << ' ';
	        }
	    }
	    cout << endl;
	}
};


template<class T>
class TwoStacksOptimal
{
 private: 
	T *stacks; 
	int length; 
	int stackTop1; 
	int stackTop2; 
 public:	
	TwoStacksOptimal(int size)
	 :length(size), stackTop1(0), stackTop2(size - 1)
	{
		stacks = new T[size];
	}
	
	~TwoStacksOptimal()
	{
	    delete[] stacks;
	}
	
	void pushFlexStack1(T value)
	{
	   if(isFullStack1())
	   {
	        cout << "Error: The stack is alread full.";
	        return;
	   }
	   if(length == 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return;
	   }
	    stacks[stackTop1] = value;
	    stackTop1++;
	    display();
	}
	
	void pushFlexStack2(T value)
	{
	    if(isFullStack2())
	    {
	        cout << "Error: The stack is alread full." << endl;
	        return;
	    }
	    if(length == 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return;
	   }
	    stacks[stackTop2] = value;
	    stackTop2--; 
	    display();
	}
	
	T popFlexStack1()
	{
	    if(isFullStack1())
	    {
	        stackTop1--;
	    }
	    if(isEmptyStack1())
	    {
	        cout << "Error: nothing to pop" << endl;
	        exit(0);
	    }
	    T temp = stacks[stackTop1];
	    stackTop1--;
	    return temp;
	}
	
	T popFlexStack2()
	{
	    if(isFullStack2())
	    {
	        stackTop2++;
	    }
	    if(isEmptyStack2())
	    {
	        cout << "Error: nothing to pop" << endl;
	        exit(0);
	    }
	    T temp = stacks[stackTop2];
	    stackTop2++;
	    return temp;
	}
	
	bool isFullStack1()
	{
	    if(stackTop1 > stackTop2)
	    {
	        return true;
	    }
	    return false;
	}
	
	bool isFullStack2()
	{
	    if(stackTop2 < stackTop1 || stackTop2 == 0)
	    {
	        return true;
	    }
	    return false;
	}
	bool isEmptyStack1()
	{
	    if(length == 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return true;
	   }
	    if(stackTop1 < 0)
	    {
	        return true;
	    }
	    return false;
	}
	
	bool isEmptyStack2()
	{
	    if(length = 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return true;
	   }
	    if(stackTop2 >= (length))
	    {
	        return true;
	    }
	    return false;
	}
	
	void display()
	{
	    if(length == 0)
	   {
	       cout << "Error:array size 0" << endl;
	       return;
	   }
	    for(int i = 0; i < length; i++)
	    {
	        if(i < stackTop1)
	        {
	            cout << stacks[i] << ' ';
	        }
	        else if(i > stackTop2)
	        {
	            cout << stacks[i] << ' ';
	        }
	        else
	        {
	            cout << ' ';
	        }
	    }
	    cout << endl;
	}
};

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
	
	//first move n-1 to second stack 
	//the move n to the last stack 
	//then move n-1 to the last stack 
	
	//i dont know how to cout the stack names. 
	
	if(n == 0)
	{
		cout << "Moved " << n << " from peg " ;
		C.push(A.top());
		A.pop();
	}
	else
	{
		showTowerStates(n - 1, A, C, B); 
		
		cout << "Moved " << n << " from peg A to C";
		C.push(A.top());
		A.pop();
		
		showTowerStates(n - 1, B, A, C);
	}
}
#endif
