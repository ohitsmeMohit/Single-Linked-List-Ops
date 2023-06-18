#include<iostream>
using namespace std;

class Node  {
    public:
    int data;
    Node* next;
    Node(int data)  {
        this->data = data;
        this->next = nullptr;
    }
};


class LinkedList    {
    private:
    Node* head;
    int size;
    public:
    LinkedList()    {
        this->head = nullptr;
        this->size = 0;
    }

    void insertAtBeginning(int value)    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head=newNode;
        size++;
        display();
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if(head== nullptr) {
            head = newNode;
            size++;
            return;
        }
        Node* current = head;
        while(current->next != nullptr ){
            current = current->next;
        }
        current->next =newNode;
        size++;
        display();
    }

    void insertAtIndex(int value, int index)    {
        if(index==0)    {
            insertAtBeginning(value);
            return;
        }
        if(index==size) {
            insertAtEnd(value);
            return;
        }
        Node* temp = head;
        for(int i=1;i<index;i++)
        {   temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        display();
    }

    void deleteFirst()   {
        if(head== nullptr)  {
            cout<<"List is Empty";
            return;
        }
        Node* temp = head;
        head = temp->next;
        size--;
        cout<<"Value removed:"<<temp->data<<endl;
//        int value = head->data;
        delete temp;
        display();
    }

    void deleteLast()   {
        if(size<=1) {
            deleteFirst();
            return;
        }
        Node* temp = get(size-2);
        int value = get(size-1)->data;
        temp->next = nullptr;
        size--;
        cout<<"Value removed:"<<value<<endl;
        delete temp;
        display();
    }

    void deleteAtIndex(int index)   {
        if(index==0)    {
            deleteFirst();
            return;
        }
        if(index==size) {
            deleteLast();
            return;
        }
        Node* prev = get(index - 1);
        int value = prev->next->data;
        prev->next = prev->next->next;
        cout<<"Value removed:"<<value<<endl;
        size--;
        display();
//        delete temp;
    }

    Node* get(int index)    {
        Node* newnode = head;
        for(int i=0;i<index;i++)
        {   newnode =newnode->next;
        }
        return newnode;
    }

    void display()  {
        Node* current = head;
        if(head== nullptr)
        {   cout<<"List is Empty"<<endl;
            return ;
        }
        while(current!= nullptr)
        {   cout<<current->data<<"->";
            current = current->next;
        }
        cout<<"End"<<endl;
        cout<<"The size of list is: "<<size<<endl;
    }

};

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