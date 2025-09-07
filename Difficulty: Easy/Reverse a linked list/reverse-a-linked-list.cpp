/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
        return prev;
        
    }
};