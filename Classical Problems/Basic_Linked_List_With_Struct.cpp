#include <iostream>

using namespace std;

struct Node{
   int data;
   Node* next;

   Node(int value){
      data = value;
      next = nullptr;
   }

   
};

struct LinkedList{
   Node* head;

   LinkedList(){
      head = nullptr;
   }

   void traverse(){
      Node* temporary = head;
      while(temporary != nullptr){
         cout<<temporary->data<<" ";
         temporary = temporary->next;
      }
   }

   void insert_head(int data){
      Node* new_node = new Node(data);
      new_node->next = head;
      head = new_node;
   }
};

int main(){
   LinkedList test;
   Node* head = new Node(1);
   Node* node1 = new Node(2);
   Node* node2 = new Node(3);
   head->next = node1;
   node1->next = node2;
   test.head = head;
   test.insert_head(0);
   test.traverse();
}
