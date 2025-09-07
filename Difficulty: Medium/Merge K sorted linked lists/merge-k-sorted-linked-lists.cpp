/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        Node* result = new Node(-1);
        Node* track = result;
        vector<int> numbers;
        for(int i = 0;i<arr.size();i++){
            Node *current = arr[i];
            
            while(current != nullptr){
                numbers.push_back(current->data);
                current = current->next;
            }
        }
        sort(numbers.begin(),numbers.end());
        for(int i = 0;i<numbers.size();i++){
            Node *newNode = new Node(numbers[i]);
            track->next = newNode;
            track = track->next;
        }
        return result->next;
        
    }
};