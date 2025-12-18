#include <iostream>
using namespace std;

// Function to calculate and return the sum of two integers
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

int count(Node* head){
   int size = 0;
   Node* temporary = head;
   while(temporary != nullptr){
      size++;
      temporary = temporary->next;
   }
   return size;
}

bool search(Node* head, int data){
   Node* temp = head;
   while(temp != nullptr){
      if(data == temp->data){
         return true;
      }
      temp = temp->next;
   }
   return false;
}

void deleteNode(Node* &head, int key){
   if(head == nullptr){
      return;
   }

   if(head->data == key){
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
   }

   Node* current = head;
   Node* previous = nullptr;

   while(current != nullptr && current->data != key){
      previous = current;
      current = current->next;
   }

   if(current == nullptr){
      return;
   }

   previous->next = current->next;
   delete current;
   return;
}


void reverse(Node* &head){
   if(head == nullptr){
      return;
   }
   if(head->next == nullptr){
      return;
   }
   
   Node* previous = nullptr;
   Node* current = head;
   Node* next = head->next;
   while(current != nullptr){
      current->next = previous;
      previous = current;
      current = next;
      if (current != nullptr) 
      { next = current->next; 
      }
      
   }
   head = previous;
}

bool detect_cycle(Node* head){
   if(head == nullptr){
      return false;
   }

   Node* slow = head;
   Node*fast = head;
   while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast){
         return true;
      }
   }
   return false;
}

int main(){
   Node* head = new Node;
   Node* node1 = new Node;
   Node* node2 = new Node;
   Node* node3 = new Node;
   Node* node4 = new Node;

   head->data = 1;
   node1->data = 2;
   node2->data = 3;
   node3->data = 4;
   node4->data = 5;

   head->next = node1;
   node1->next = node2;
   node2->next = node3;
   node3->next = node4;
   node4->next = node3;

   cout<<detect_cycle(head);
   
}
