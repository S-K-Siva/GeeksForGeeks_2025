class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        if(arr.size() == 1) return;
        int n = arr.size();
        int front = 0;
        int rear = 0;
        
        while(rear < n){
            while(rear < n && arr[rear] == 1){
                rear++;
            }
            if(rear < n && arr[rear] == 0){
                swap(arr[front],arr[rear]);
                front++;
                rear++;
            }
        }
        
    }
};