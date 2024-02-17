class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for(int i=0; i<s.length(); i++){
            if(isalnum(s[i])){
                ans+=s[i];
            }
        }
        int i=0;
        int n=ans.length();
        int j=n-1;
        while(i<j){
            if(ans[i] != ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};