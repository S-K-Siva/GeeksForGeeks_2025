//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create BufferedReader for efficient input reading
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read number of test cases
        int T = Integer.parseInt(br.readLine());

        // Process each test case
        while (T-- > 0) {
            // Read the entire line containing the array elements
            String line = br.readLine();

            // Split the line into an array of strings, then parse them as integers
            String[] tokens = line.split("\\s+");
            int[] a = new int[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                a[i] = Integer.parseInt(tokens[i]);
            }

            // Create the Solution object
            Solution obj = new Solution();

            // Call maxLen function and print the result
            System.out.println(obj.maxLen(a));
        }
    }
}
// } Driver Code Ends


class Solution {
    public int maxLen(int[] arr) {
        int n = arr.length;
        
        for(int i = 0;i<n;i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        int prefixSum = 0;
        
     
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        int result = 0;
        
        for(int i = 0;i<n;i++){
            prefixSum += arr[i];
            if(prefixSum == 0){
                result = i + 1;
            }
            
            if(tm.containsKey(prefixSum))
                result = Math.max(result, i - tm.get(prefixSum));
            else
                tm.put(prefixSum, i);
            
            
        }
        return result;
        
    }
}
