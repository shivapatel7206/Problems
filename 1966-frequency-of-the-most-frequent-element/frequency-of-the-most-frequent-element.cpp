class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        long long max_res=1;
        long long temp=k;
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(long long i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(long long i=1;i<n;i++){
            long long low=0;
            long long high=i-1;
            while(low<=high){
                long long mid=low+(high-low)/2;
                long long temp_sum=(i-mid)*nums[i]-(pre[i]-nums[i]-pre[mid]+nums[mid]);
                if(temp_sum>k){
                    low=mid+1;
                }else{
                    max_res=max(i-mid+1,max_res);
                    high=mid-1;
                }
            }
        }
        return  max_res;
    }
};