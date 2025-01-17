//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = inputLine.length;
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            Solution ob = new Solution();
            int[] ans = new int[n];
            ans = ob.productExceptSelf(arr);

            for (int i = 0; i < n; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
            System.out.println("~");
            t--;
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public static int[] productExceptSelf(int arr[]) {
        int n = arr.length;
        int[] leftArr = new int[n];
        int[] rightArr = new int[n];
        leftArr[0] = arr[0];
        rightArr[n-1] = arr[n-1];
        
        for(int i = 1;i<n;i++){
            leftArr[i] = arr[i] * leftArr[i-1];
        }
        
        for(int i = n-2;i>=0;i--){
            rightArr[i] = arr[i] * rightArr[i+1];
        }
        
        int[] result = new int[n];
        for(int i = 0;i<n;i++){
            if(i == 0){
                result[i] = rightArr[i+1];
            }else if(i == n-1){
                result[i] = leftArr[i-1];
            }else{
                result[i] = leftArr[i-1] * rightArr[i+1];
            }
        }
        
        return result;
    }
}
