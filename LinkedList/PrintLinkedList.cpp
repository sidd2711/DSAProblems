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

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    PrintList(head);
    return 0;
}