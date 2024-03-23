//Solution 01:
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        findComb(0, candidates, target, ans, temp);
        return ans;
    }
    
    void findComb(int index, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp){
      
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
            
        if(candidates[index] <= target){
            //pick 
            temp.push_back(candidates[index]);
            findComb(index, candidates, target-candidates[index], ans, temp);
            //not got ans so pop all element
            temp.pop_back();
        }
        findComb(index+1, candidates, target, ans, temp);
    }
};