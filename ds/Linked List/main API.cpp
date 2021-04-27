#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
}*head;

void traverse();
void push_back(int);
void push_front(int);
void pop_back();
void pop_front();
void reverse();

void traverse() {
    if(head != NULL) {
        Node* temp = new Node();
        temp = head;
        cout << "\n Nodes : ";
        while(temp != NULL) {
            cout << "\t" << temp->data;
            temp = temp->next;
        }
        delete temp;
    } else {
        cout << "\n List is Empty - (First add a Node)";
    }
}

void push_back(int ele) {
    Node* newele = new Node();
    newele->data = ele;
    newele->next = NULL;
    if(head == NULL) {
        head = newele;
    } else {
        Node* temp = new Node();
        for(temp = head; temp->next != NULL; temp = temp->next);
        temp->next = newele;
    }
}

void push_front(int ele) {
    Node* newele = new Node();
    newele->data = ele;
    newele->next = NULL;
    if(head == NULL) {
        head = newele;
    } else {
        newele->next = head;
        head = newele;
    }
}

void pop_back() {
    if(head == NULL) {
        cout << "\n List is Empty";
    } else {
        Node* temp = new Node();
        for(temp = head; (temp->next)->next != NULL; temp = temp->next);
        delete temp->next;
        temp->next = NULL;
    }

}

void pop_front() {
    if(head == NULL) {
        cout << "\n List is Empty";
    } else {
        Node* temp = new Node();
        if(head->next == NULL) {
            temp = head;
            head = NULL;
            delete temp;
        } else {
            temp = head;
            head = temp->next;
            delete temp;
        }
    }
}

void reverse() {
    Node* current = new Node();
    Node* pre = new Node();
    Node* post = new Node();
    current = head;
    pre = NULL;
    post = current->next;
    while(current->next != NULL) {
        current->next = pre;
        pre = current;
        current = post;
        post = post->next;
    }
    current->next = pre;
    head = current;
}


int main()
{

    head = NULL;
    int ch, ele;
    while(ch != 10) {
        cout << "\n0. Traverse";    //O(n)
        cout << "\n1. Add Node to End";   //O(1), in worst case (when array is full) O(n)
        cout << "\n2. Add Node to Front";  //O(n)
        cout << "\n3. Remove from back";    //O(1)
        cout << "\n4. Remove from front";   //O(n)
        cout << "\n5. Reverse List";
        cout << "\n\n6. Exit";
        cout << "\n\nEnter your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 0: traverse();
            break;
        case 1:
            cout << "\n Enter the Element to be Added at End : ";
            cin >> ele;
            push_back(ele);
            break;
        case 2:
            cout << "\n Enter the Element to be Added Front : ";
            cin >> ele;
            push_front(ele);
            break;
        case 3:
            pop_back();
            break;
        case 4:
            pop_front();
            break;
        case 5:
            reverse();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\n Enter correct choice, try again...";
            break;
        }
    }
    return 0;
}
