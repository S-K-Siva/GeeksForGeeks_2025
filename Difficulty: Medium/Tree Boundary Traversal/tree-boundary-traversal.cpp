//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

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
    void leftViewHandle(Node *root, vector<int>& res){
        Node *current = root;
        while(current != nullptr){
            if(current->left != nullptr || current->right != nullptr)
                res.push_back(current->data);
            if(current->left){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        
    }
    void rightViewHandle(Node *root, vector<int>& res)
    {
        Node *current = root;
        while(current != nullptr){
            if(current->left != nullptr || current->right != nullptr){
                res.push_back(current->data);
            }
            if(current->right) current = current->right;
            else current = current->left;
        }
    }
    void inorderTraversal(Node *root, vector<int>& res){
        if(!root) return;
        inorderTraversal(root->left, res);
        if(root->left == nullptr && root->right == nullptr)
            res.push_back(root->data);
        inorderTraversal(root->right,res);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};
        vector<int> result;
        result.push_back(root->data);
        if(root->left == nullptr && root->right == nullptr){
            return result;
        }
        vector<int> leftView,rightView,bottomView;
        leftViewHandle(root->left, leftView);
        rightViewHandle(root->right, rightView);
        inorderTraversal(root, bottomView);
        reverse(rightView.begin(),rightView.end());
        result.insert(result.end(),leftView.begin(),leftView.end());
        result.insert(result.end(), bottomView.begin(),bottomView.end());
        result.insert(result.end(), rightView.begin(), rightView.end());
        return result;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends