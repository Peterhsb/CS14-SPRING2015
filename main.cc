#include <iostream>
#include <stack>
#include "lab3.h"

using namespace std;

int main()
{
    cout << "Testing TwoStacksFixed class." << endl;
    TwoStacksFixed<char> test(9, 4);
    test.pushStack1('a');
    test.pushStack1('b');
    test.pushStack1('c');
    test.pushStack1('d');
    test.pushStack1('e');
    //test.pushStack1('f');
    test.pushStack2('a');
    test.pushStack2('b');
    test.pushStack2('c');
    test.pushStack2('d');
    test.pushStack2('e');
    
    // cout << test.popStack1() << endl;
    // cout << test.popStack1() << endl;
    // cout << test.popStack1() << endl;
    // cout << test.popStack1() << endl;
    // cout << test.popStack1() << endl;
    // cout << test.popStack1() << endl;
    cout << test.popStack2() << endl;
    cout << test.popStack2() << endl;
    cout << test.popStack2() << endl;
    
    cout << "Testing TwoStacksOptimal class." << endl;
    TwoStacksOptimal<char> test2(9);
    test2.pushFlexStack1('a');
    test2.pushFlexStack1('b');
    test2.pushFlexStack1('c');
    test2.pushFlexStack1('d');
    test2.pushFlexStack1('e');
    //test2.pushStack1('f');
    test2.pushFlexStack2('a');
    test2.pushFlexStack2('b');
    test2.pushFlexStack2('c');
    test2.pushFlexStack2('d');
    test2.pushFlexStack2('e');
    
    stack<int> first;
    first.push(5);
    first.push(4);
    first.push(3);
    first.push(2);
    first.push(1);
    stack<int> second;
    stack<int> third;
    showTowerStates(5, first, second, third);
    return 0;
}
