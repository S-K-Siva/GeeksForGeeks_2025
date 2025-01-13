//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().maxWater(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public int maxWater(int arr[]) {
        int n = arr.length;
        int low = 0;
        int high = n-1;
        
        int result = 0;
        while(low < high){
            result = Math.max(result, (high - low)*Math.min(arr[low],arr[high]));
            
            if(arr[low] < arr[high]){
                ++low;
            }else{
                --high;
            }
        }
        return result;
    }
}