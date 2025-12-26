#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
void insert_tail(Node* &head,int data){
    if(head == nullptr){
        head = new Node{data,nullptr};
        return;
    }
    Node* temporary = head;
    while(temporary->next){
        temporary = temporary ->next;
    }
    temporary->next = new Node{data,nullptr};
    return;
}
void print(Node* head){
    Node* temporary = head;
    while(temporary != nullptr){
        cout<<temporary->data;
        temporary = temporary->next;
    }
    return;
}

Node* partition(Node* head, int x){
    Node* smallhead = new Node{0,nullptr};
    Node* smalltail = smallhead;
    Node* greathead = new Node{0,nullptr};
    Node* greattail = greathead;
    Node* temporary = head;
    while(temporary != nullptr){
        if(x > temporary->data){
            insert_tail(smallhead, temporary->data);
        }
        else{
            insert_tail(greathead, temporary->data);
        }
        temporary = temporary->next;
    }

    while(smalltail->next != nullptr){
        smalltail = smalltail->next;
    }

    while(greattail->next != nullptr){
        greattail = greattail->next;
    }

    if(smalltail != nullptr){
        smalltail->next = greathead->next;
    }

    return smallhead->next;

}

int main(){
    Node* head = new Node{1,nullptr};
    Node* node1 = new Node{2,nullptr};
    Node* node2 = new Node{3,nullptr};
    Node* node3 = new Node{4,nullptr};
    Node* node4 = new Node{0, nullptr};

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Node* result = partition(head,2);
    print(result);
}
