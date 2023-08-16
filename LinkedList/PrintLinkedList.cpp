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
        cout<<head->data<<endl;
        head = head->next;
    }
}

Node* InsertBegin(Node* head,int data){
    Node* temp = new Node(data);
    temp -> next = head;
    return temp;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    PrintList(head);

    head = InsertBegin(head,5);
    head = InsertBegin(head,4);
    head = InsertBegin(head,3);

    PrintList(head);
    return 0;
}