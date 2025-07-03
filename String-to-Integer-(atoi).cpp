class Solution {
public:
    int myAtoi(string s) {
        
        long res = 0;

        int idx = 0;
        while(idx < s.size() && s[idx] == ' '){
            idx++;
        }

        int sign = 1;
        if(s[idx] == '-'){
            sign = -1;
            idx++;
        }
        else if(s[idx] == '+')
            idx++;
        
        while(idx < s.size())
        {
            int digit = s[idx++] - '0';
            if(digit >= 0 && digit <= 9)
                res = (res*10) + digit;
            else
                break;
            
            if(sign * res > INT_MAX) return INT_MAX;
            if(sign * res < INT_MIN) return INT_MIN;
        }

        return res * sign;
    }
};