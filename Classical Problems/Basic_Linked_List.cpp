#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};

void traversal(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    return;
}

void insert_head(Node* &head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return;

}

void delete_linkedlist(Node* &head){
    Node* temporary = head;
    while(temporary != nullptr){
        Node* deleted = temporary;
        temporary = temporary->next;
        delete deleted;
    }
    head = nullptr;
    return;
}

void insert_tail(Node* &head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if(head == nullptr){
        head = new_node;
        return;
    }
    Node* temporary = head;
    while(temporary->next != nullptr){
        temporary = temporary->next;
    }
    temporary->next = new_node;
}

void insert_middle(Node*& head, int data, int position) {
    // Insert at head
    if (position == 0 || head == nullptr) {
        insert_head(head, data);
        return;
    }

    Node* new_node = new Node{data, nullptr};
    Node* temporary = head;
    int index = 0;

    // Move to the node BEFORE the insertion point
    while (temporary->next != nullptr && index < position - 1) {
        temporary = temporary->next;
        index++;
    }

    // Insert in the middle or at the tail
    new_node->next = temporary->next;
    temporary->next = new_node;
}

void delete_head(Node* &head){
    if(head->next == nullptr){
        Node* deleted = head;
        delete deleted;
        head = nullptr;
        return;
    }
    Node* deleted = head;
    head = head->next;
    delete deleted;
    return;
}

void delete_tail(Node* &head){
    Node* temporary = head;
    Node* previous = nullptr;
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        Node* deleted = head;
        delete deleted;
        head = nullptr;
        return;
    }
    while(temporary->next != nullptr){
        previous = temporary;
        temporary = temporary->next;
    }

    Node* deleted = temporary;
    previous->next = nullptr;
    delete deleted;
    return;

}

int main(){
    Node* head = new Node;
    Node* node1 = new Node;
    Node* node2 = new Node;

    head->data = 1;
    node1->data = 2;
    node2->data = 3;

    head->next = node1;
    node1->next = node2;
    node2->next = nullptr;
    insert_middle(head,100,1);
    traversal(head);
}
