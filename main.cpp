#include<iostream>
#include "single.cpp" // Include the header file or the implementation file

using namespace std;

int main()
{   LinkedList ll;
    ll.insertAtBeginning(12);
    ll.insertAtBeginning(11);
    ll.insertAtBeginning(10);
    cout<<ll.get(2)->data<<endl;
    ll.insertAtEnd(90);
    ll.insertAtIndex(31, 2);
    ll.insertAtBeginning(9);
    ll.deleteLast();
    ll.insertAtEnd(30);
    ll.insertAtIndex(25, 1);
    ll.insertAtBeginning(56);
    ll.deleteAtIndex(3);
    cout<<"Final LL: ";
    ll.display();
    return 0;
}