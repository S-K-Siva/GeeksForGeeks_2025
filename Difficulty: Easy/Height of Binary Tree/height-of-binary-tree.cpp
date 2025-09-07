/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        if (node == nullptr) return -1;       // empty has height -1
        if (node->left == nullptr && node->right == nullptr) return 0;
        int left = height(node->left);
        int right = height(node->right);
        return 1 + max(left, right);
    }
};