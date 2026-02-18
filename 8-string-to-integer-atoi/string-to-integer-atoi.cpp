class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
      
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        string num = "";  
        int count = 0;     
        

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            num.push_back(s[i]);
            i++;
        }
        

        while (i < n && isdigit(s[i])) {
            num.push_back(s[i]);
            count++;
            i++;
        }
        if (count == 0) return 0;

        long long result = 0;
        int sign = 1;
        int start = 0;
        
        if (num[0] == '-') {
            sign = -1;
            start = 1;
        } 
        else if (num[0] == '+') {
            start = 1;
        }
        
        for (int j = start; j < num.length(); j++) {
            result = result * 10 + (num[j] - '0');
            

            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;
        }
        
        return sign * result;
    }
};
