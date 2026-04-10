class Solution {
public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if(n < 3) return {};

        vector<int> leftMin(n), rightMax(n);

        // Step 1: Fill leftMin
        leftMin[0] = arr[0];
        for(int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i-1], arr[i]);
        }

        // Step 2: Fill rightMax
        rightMax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }

        // Step 3: Find triplet
        for(int i = 1; i < n-1; i++) {
            if(leftMin[i-1] < arr[i] && arr[i] < rightMax[i+1]) {
                return {leftMin[i-1], arr[i], rightMax[i+1]};
            }
        }

        return {};
    }
};