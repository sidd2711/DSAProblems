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

Node* InsertPos(Node* head, int x,int pos){
    
    Node* temp = new Node(x);
    Node* curr = head;

    //Handle the case of changing head
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    while(pos > 2 && curr != NULL){
        curr = curr->next;
        pos--;
    }

    //Handled the position greater than length of linkedlist.
    if(curr == NULL) return head;
    
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

Node* DeleteHead(Node* head){
    if(head == NULL) return NULL;
    else{
        Node* temp = head->next;
        delete head;
        return temp;
    }
}

Node* DeleteTail(Node* head){
    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* curr = head;
    while(curr->next->next != NULL) curr = curr->next;

    delete(curr->next);
    curr->next = NULL;
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
    
    head = InsertPos(head, 1, 1);
    head = InsertPos(head,25,7);
    head = InsertPos(head,80,13);
    head = InsertPos(head,999, 50);

    cout<<"After insert position: ";
    PrintList(head);
    cout<<endl;

    head = DeleteHead(head);

    cout<<"After deleting head: ";
    PrintList(head);
    cout<<endl;

    head = DeleteTail(head);

    cout<<"After deleting tail: ";
    PrintList(head);
    cout<<endl;

    return 0;
}