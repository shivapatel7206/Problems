class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        double res = 0;
        bool dig = false;
        bool posi = false;
        bool neg = false;
        bool other = false;

        int i = 0;
        while (i < n && s[i] == ' ')
            i++;

        for (; i < n; i++) {
            if (other)
                break;
            
            if (s[i] >= '0' && s[i] <= '9') {
                res = (res * 10) + (s[i] - '0');
                dig = true;
            } else {
                if (dig)
                    break;

                else if (s[i] == '-' && !neg)
                    neg = true;

                else if (s[i] == '+' && !posi)
                    posi = true;

                else
                    other = true;
            }
        }

        if (posi && neg)
            return 0;

        if (neg)
            res = -res;

        if (res > INT_MAX)
            return INT_MAX;

        if (res < INT_MIN)
            return INT_MIN;

        return (int)res;
    }
};