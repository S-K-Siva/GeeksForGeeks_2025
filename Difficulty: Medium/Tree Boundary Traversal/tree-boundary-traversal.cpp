/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    void leftBoundary(Node *root, vector<int>& track){
        Node *current = root;
        while(current != nullptr){
        if(current->left != nullptr || current->right != nullptr){
            track.push_back(current->data);
        }
        if(current->left)
            current = current->left;
        else
            current = current->right;
        }
    }
    void rightBoundary(Node *root, vector<int>& track){
        Node *current = root;
        while(current != nullptr){
        if(current->left != nullptr || current->right != nullptr){
            track.push_back(current->data);
        }
        if(current->right)
            current = current->right;
        else
            current = current->left;
        }
    }
    
    void inorder(Node *root, vector<int>& track){
        if(!root) return;
        inorder(root->left,track);
        if(root->left == nullptr && root->right == nullptr){
            track.push_back(root->data);
            return;
        }
        inorder(root->right,track);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};
        if(root->left == nullptr && root->right == nullptr) return {root->data};
        vector<int> result = {root->data};
        vector<int> left, right, bottom;
        leftBoundary(root->left, left);
        rightBoundary(root->right, right);
        reverse(right.begin(),right.end());
        inorder(root,bottom);
        result.insert(result.end(),left.begin(),left.end());
        result.insert(result.end(),bottom.begin(),bottom.end());
        result.insert(result.end(),right.begin(),right.end());
        
        return result;
    }
};