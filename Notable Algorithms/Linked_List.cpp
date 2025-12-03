#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* next;
};


struct List{
    Node* pHead;
    int size;

    Node* createNode(int data);

};

Node* createNode(int data){
    Node* node = new Node;
    node->key = data;
    node->next = nullptr;
    return node;
}


void addhead(Node*& pHead, int data){
    Node* newNode = createNode(data);
    newNode->next = pHead;
    pHead = newNode;
}

void addtail(Node*& pHead, int data){
    Node* newNode = createNode(data);
    if (pHead == nullptr) {
        pHead = newNode;
        return;
    }
    Node* temporary = pHead;
    while (temporary->next != nullptr) {
        temporary = temporary->next;
    }
    temporary->next = newNode;
}

void addmid(Node*& pHead, int position, int data){
    Node* new_node = createNode(data);
    Node* temporary = pHead;
    Node* temporary_previous;
    if(position == 0){
        addhead(pHead, data);
        return;

    }
    else{
        while(position != 0 && temporary->next != nullptr){
            temporary_previous = temporary;
            temporary = temporary->next;
            position--;
        }
    }
    if(temporary->next == nullptr){
        addtail(pHead, data);
        return;
    }
    new_node->next = temporary;
    temporary_previous->next = new_node;

}

void deletehead(Node* & pHead){
    if (pHead == nullptr) return;   // nothing to delete

    Node* oldHead = pHead;          // save the current head
    pHead = pHead->next;            // move head forward
    delete oldHead; 
}

void deletetail(Node* & pHead){
    Node* temporary = pHead;
    while((temporary->next)->next != nullptr){
        temporary = temporary->next;
    }
    Node* target_node = temporary->next;
    temporary->next = nullptr;
    delete target_node;
    return;

    
}

void traverse(Node* head) {
    Node* current = head;          // start at the head
    while (current != nullptr) {   // keep going until the end
        cout << current->key << " ";  // process the data
        current = current->next;      // move to the next node
    }
    cout << endl;
}


// int main() {
//     Node* node1 = createNode(1);
//     Node* node2 = createNode(3);
//     Node* node3 = createNode(7);
//     Node* node4 = createNode(8);
//     int n = 4;

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;

//     Node* node5 = createNode(2);
//     Node* node6 = createNode(3);
//     Node* node7 = createNode(5);
//     int m = 3;

//     List Array;



// }
