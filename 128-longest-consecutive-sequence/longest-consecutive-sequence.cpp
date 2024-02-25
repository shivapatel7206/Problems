class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int ls=INT_MIN;
        int count=0;
        int lg=1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]-1==ls){
                count++;
                ls=nums[i];
            }
            else if(nums[i]!=ls){
                count=1;
                ls=nums[i];
            }
            lg=max(count,lg);
        }
        return lg;
    }
};