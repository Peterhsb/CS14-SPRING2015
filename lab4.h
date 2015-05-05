//Name: Han Sung Bae
//SID: 861143990
//Date: 5/4/2015

#include <iostream>
#include <utility>
#include <cstdlib>
#include <queue>

using namespace std;


template <typename item>
void printPreorder(item k);

template <typename item>
void printPostorder(item k);

template <typename item>
void preorder(item m, item n, item k);

template <typename item>
void postorder(item m, item n, item k);

template <typename item>
void printSort(item k);

template <typename item>
void sort(item m, item n, item i, item k, priority_queue<pair<item,item> > List);



template <typename item>
void printPreorder(item k)
{
    preorder(2, 1, k);  //left subtree
    preorder(3, 1, k);  //right subtree
}

template <typename item>
void printPostorder(item k)
{
    postorder(2, 1, k);  //left subtree
    postorder(3, 1, k);  //right subtree
}

template <typename item>
void preorder(item m, item n, item k)
{
    pair<item, item> node(m, n);
    
    if((node.first + node.second) >= k ) { return; }
    
    cout << node.first << " " << node.second << endl;
    
    preorder(2*m - n, m, k);     //traverse left tree
    preorder(2*m + n, m, k);     //traverse middle tree
    preorder(m + 2*n, n, k);        //traverse right tree
}

template <typename item>
void postorder(item m, item n, item k)
{
    pair<item, item> node(m, n);
    
    if((node.first + node.second) >= k ) { return; }
    
    postorder(2*m - n, m, k);     //traverse left tree
    postorder(2*m + n, m, k);     //traverse middle tree
    postorder(m + 2*n, n, k);        //traverse right tree
    
    cout << node.first << " " << node.second << endl;
}

template <typename item>
void printSort(item k)
{
    priority_queue< pair<item, item> > pairList; 
    
    for(item i = 3; i < k; i++)
    {
        sort(2, 1, k, i, pairList);
        sort(3, 1, k, i, pairList);
    }
}

template <typename item>
void sort(item m, item n, item k, item i, priority_queue<pair<item, item> > List)
{
    pair<item, item> primes(m, n);
    if((primes.first + primes.second) >= k) { return; }
    if((primes.first + primes.second) == i) { List.push(primes); }
    
    sort((2*m) - n, m, k, i, List);     //traverse left tree
    sort((2*m) + n, m, k, i, List);     //traverse middle tree
    sort(m + (2*n), n, k, i, List);        //traverse right tree
    
    //to print
    while(!List.empty())
    {
        cout << List.top().first << " " << List.top().second << endl;
        List.pop();
    }
}
