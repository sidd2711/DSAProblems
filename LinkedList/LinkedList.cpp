#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void PrintList(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* InsertBegin(Node* head,int data){
    Node* temp = new Node(data);
    temp -> next = head;
    return temp;
}

Node* InsertEnd(Node* head, int x){
    Node* temp = new Node(x);

    if(head == NULL) return temp;

    Node* curr = head;
    while(curr->next != NULL) curr = curr -> next;

    curr->next = temp;

    return head;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    PrintList(head);
    cout<<endl;

    head = InsertBegin(head,5);
    head = InsertBegin(head,4);
    head = InsertBegin(head,3);

    cout<<"After Insert Begin: ";
    PrintList(head);
    cout<<endl;

    head = InsertEnd(head,50);
    head = InsertEnd(head,60);
    head = InsertEnd(head,70);

    cout<<"After insert end: ";
    PrintList(head);
    cout<<endl;
    
    return 0;
}