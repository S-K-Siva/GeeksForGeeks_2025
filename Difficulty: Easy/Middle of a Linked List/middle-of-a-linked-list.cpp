/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        int length = 0;
        Node* track;
        track = head;
        while(track != nullptr){
            ++length;
            track = track->next;
        }
        int mid = length/2;
        track = head;
        int counter = 0;
        while(track != nullptr && counter++ != mid){
            track = track->next;
        }
        return track->data;
    }
};