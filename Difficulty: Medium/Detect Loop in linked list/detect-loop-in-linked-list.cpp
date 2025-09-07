/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        if(head == nullptr || head->next == nullptr) return false;
        Node *slow=head;
        Node *fast = head->next;
        
        while(slow && fast && slow->next != nullptr && fast->next != nullptr){
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};