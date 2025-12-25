#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Dummy node to simplify logic
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;
    while(l1||l2||carry){
        int s = carry;
        if(l1 != nullptr){
            s += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            s += l2->val;
            l2 = l2->next;
        }
        carry = s/10;
        s = s%10;
        ListNode* temporary = new ListNode(s);
        current->next = temporary;
        current = current->next;

    }
    return dummy->next;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Example: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);
    printList(result); // Output: 7 -> 0 -> 8 -> NULL

    return 0;
}
