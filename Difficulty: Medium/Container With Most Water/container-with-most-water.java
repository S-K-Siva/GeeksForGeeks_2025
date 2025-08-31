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