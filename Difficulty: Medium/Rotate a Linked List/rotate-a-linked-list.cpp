//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    
    Node* rotate(Node* head, int k) {
        if(head == nullptr) return head;
        Node* temp = head;
        int length = 0;
        while(temp){
            ++length;
            temp = temp->next;
        }
        
        int rotateValidate = k % length;
        if(rotateValidate == 0) return head;
        temp = head;
        Node *prev;
        prev = nullptr;
        while(temp && rotateValidate)
        {
            prev = temp;
            temp = temp->next;
            --rotateValidate;
        }
        
        if(prev == nullptr) return head;
        prev->next = nullptr;
        Node *returnHead;
        returnHead = temp;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = head;
        head = returnHead;
        return head;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends