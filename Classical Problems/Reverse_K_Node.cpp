#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int length = 0;
    ListNode* temporary = head;
    while(temporary != nullptr){
        length++;
        temporary = temporary->next;
    }

    ListNode* previous = dummy;
    while(length >= k){
        ListNode* current = previous->next;
        ListNode* next = current->next;
        for(int i = 1; i < k; i++){
            current->next = next->next;
            next->next = previous->next;
            previous->next = next;
            next = current->next;
        }
        previous = current;
        length -= k;

    }
    return dummy->next;
}

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* newHead = reverseKGroup(head, k);

    printList(newHead); // Output: 2 1 4 3 5
    return 0;
}
