//Name: Han Sung Bae
//SID: 861143990
//Date: 5/4/2015
#include <iostream>
#include <queue>
#include "lab4.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        cout << "Usage: a.out INTEGER" << endl;
        return -1;
    }
    
    int limit = atoi(argv[1]);
    
    cout << "preorder " << endl;
    printPreorder(limit);
    
    cout << endl;
    
    cout << "postorder" << endl;
    printPostorder(limit);
    
    cout << endl;
    
    cout << "sorted " << endl;
    printSort(limit);
    return 0; 
}
