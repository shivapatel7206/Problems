#define ll long long

class Solution {
public:
    string s;
    ll goal;
    vector<string> ans;

    void recurse (string exp, ll val, ll prev, int i) {
        if (i == s.size()) { //base case
            if (val == goal) ans.push_back(exp);
            return;
        }
        for (int j=i; j<s.size(); j++) { //we'll use example "123"
//note that 'i' is the starting index of selected number, j is ending index
//so s.substr(i, j-i+1) gives the substring from i to j

            string sub = s.substr(i, j-i+1);//in each iteration: "1", "12", "123" etc.
            ll foo = stoll(sub);
            if (j>i && s[i]=='0') return; //avoid numbers with trailing zeroes
            if (i==0) { // (i==0) => it is the first number of our expression. eg: in "123", we can have "1", "12", etc.
                recurse(sub, foo, foo, j+1);
            }
            else {
                recurse(exp+"+"+sub, val+foo, foo, j+1);
                recurse(exp+"-"+sub, val-foo, -foo, j+1);
                recurse(exp+"*"+sub, val-prev+prev*foo, prev*foo, j+1); //use ex of "1-2*3" to understand: currently, (val==-1, prev==-2), so updated val == -1 - (-2) + (-2*3) == -5
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        goal = target; // just converting into 
        s = num; // global vars to avoid parameter passing
        
        recurse ("", 0, 0, 0);
        return ans;
    }
};