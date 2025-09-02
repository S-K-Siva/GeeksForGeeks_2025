/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        int length = 0;
        Node *temp = head;
        while(temp != nullptr){
            temp = temp->next;
            ++length;
        }
        
        if(k>length || length-k < 0) return head;
        Node *n1,*n2;
        n1 = head;
        n2 = head;
        int l1 = 1,l2=1;
        while(n1 != nullptr){
            if(l1 == k)break;
            n1 = n1->next;
            ++l1;
        }
        while(n2 != nullptr){
            if(l2 == length-k+1) break;
            n2 = n2->next;
            ++l2;
        }
        int t = n1->data;
        n1->data = n2->data;
        n2->data = t;
        return head;
    }
};