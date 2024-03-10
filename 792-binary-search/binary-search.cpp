class Solution {
public:
    int search(vector<int>& arr, int key) {

        int n = arr.size(); // vector gives ki kitne element present hai...
        int start=0, end = n-1, mid;

        while(start<=end) {
            //Mid to find karo
            mid = (start+end)/2;
            //arr[mid]==key
            if(arr[mid]==key)
            return mid;
            //arr[mid,key
            else if(arr[mid]<key)
            start = mid+1;
            // arr[mid]>key
            else
            end = mid-1;
        }

        return -1;
        
        }
};