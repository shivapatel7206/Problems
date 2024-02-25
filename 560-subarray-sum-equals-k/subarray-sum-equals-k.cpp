class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[sum]++;
        for(int num: nums) {
            sum += num;
            int gap = sum - k;
            if(mp.find(gap) != mp.end()) 
                count += mp[gap];
            mp[sum]++;
        }
        return count;
    }
};