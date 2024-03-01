class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        //Binary Search Algo
        while(left<= right){
            int mid = left + (right-left)/2;

            // if target is found return its index
            if(nums[mid] == target) return mid;

            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;

        }
        //returning left index as it contains the position where it would be if it were inserted in order.
        return left;
    }
};