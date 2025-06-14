/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node* root1, Node* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1 && root2 && root1->data != root2->data){
            return false;
        }
        if(solve(root1->right,root2->left) == false ||
        solve(root1->left,root2->right) == false){
            return false;
        }
        return true;
    }
    bool isSymmetric(Node* root) {
        if(!root) return true;
        return solve(root->left,root->right);
    }
};