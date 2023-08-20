#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void PrintDoublyLinkedList(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node*InsertBegin(Node* head, int x){
    Node* temp = new Node(x);
    
    if(head != NULL) head->prev = temp;
    temp->next = head;
    return temp;
}

Node* InsertEnd(Node* head, int x){

    Node* temp = new Node(x);
    if(head == NULL) return temp;
    Node* curr = head;
    while(curr->next != NULL) curr = curr->next;

    
    temp->prev = curr;
    curr->next = temp;

    return head;
}

int main(){

    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;

    PrintDoublyLinkedList(head);
    cout<<endl;

    head = InsertBegin(head,5);
    head = InsertBegin(head,4);
    head = InsertBegin(head,3);

    cout<<"After InsertBegin: ";
    PrintDoublyLinkedList(head);
    cout<<endl;

    Node* temp = NULL;
    temp = InsertBegin(temp,1);

    cout<<"After InsertBegin in Empty LL: ";
    PrintDoublyLinkedList(temp);
    cout<<endl;

    head = InsertEnd(head,40);
    head = InsertEnd(head,50);

    cout<<"After InsertEnd: ";
    PrintDoublyLinkedList(head);
    cout<<endl;

    Node* InsertEndInNull = NULL;
    InsertEndInNull = InsertEnd(InsertEndInNull,10);

    cout<<"After InsertEnd in Empty LL: ";
    PrintDoublyLinkedList(InsertEndInNull);
    cout<<endl;

    return 0;
}