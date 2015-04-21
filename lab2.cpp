#include <iostream> 
#include <forward_list>
#include "lab2.h"

using namespace std;


bool isPrime(int i);
int primeCount(forward_list<int>lst);

template <typename Type>
void listCopy( forward_list <Type> L, forward_list <Type> &P );

template <typename Type>
void printLots (forward_list <Type> L, forward_list <int> P);

int main()
{
    cout << "Creating a Lab List object: " << endl;
    List<int>L1;
    L1.print();
    L1.push(0);
    L1.push(1);
    L1.print();
    int i = 2;
    while(i <= 9)
    {
        L1.push(i);
        i++;
    }
    L1.print();
    List<int> L2 = L1.elementSwap(2);
    L1.print();
    cout <<"Testing swap on list size 2" << endl;
    List<int> L3;
    L3.push(0);
    L3.push(1);
    List<int>L4 = L3.elementSwap(0);
    L4.print();
    L3.pop_front();
    L3.elementSwap(10);
    
    
    return 0; 
}

bool isPrime(int i)
{
    if(i <= 0 || i == 1){
        return false;
    }
    for(int j = 2; j < i; j++){
        if(i % j == 0){
            return false;
        }
    }
    return true;
}

int primeCount(forward_list<int>lst)
{
    int p_counter = 0;
    for(auto it = lst.begin(); it != lst.end(); it++)
    {
        if(isPrime(*it))
        {
            p_counter++;
        }
    }
    return p_counter;
}

template <typename Type>
void listCopy( forward_list <Type> L, forward_list <Type> &P )
{
    if(L.empty())
    {
        return;
    }
    if(P.empty())
    {
        for(auto it = L.begin(); it != L.end(); it++)
        {
            P.push_front(*it);
        }
    }
    else
    {
        for(auto it = L.begin(); it != L.end(); it++)
        {
            auto it2 = P.end() - 1;
            P.insert_after(it2, *it);
        }
    }
}

template <typename Type>
void printLots (forward_list <Type> L, forward_list <int> P)
{
    for(auto it = P.begin();it != P.end(); it++)
    {
        int pos = *it;
        auto it2 = L.begin(); 
        while(pos > 0)
        {
            it2++;
            pos--;
        }
    cout << *it2 << ' '; 
    }
}
