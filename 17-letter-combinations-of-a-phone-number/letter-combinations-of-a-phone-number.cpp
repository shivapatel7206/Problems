class Solution {
public:

    void helper(int idx, int n, string &digits, vector<string> &dict, string &temp, vector<string> &res){

        if(idx == n){
            res.push_back(temp);
            return;
        }

        string katta = dict[digits[idx]-'0'];

        for(int i = 0; i < katta.size(); i++){
            temp += katta[i];
            helper(idx + 1, n, digits, dict, temp, res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        int n = digits.length();

        vector<string> res;
        vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        if(n == 0){
            return res;
        }

        string temp = "";

        helper(0, n, digits, dict, temp, res);

        return res;
    }
};