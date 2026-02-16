class Solution {
public:
    int maxDepth(string s) {

        int maxDepth = 0;
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                count += 1;
            }
            if(s[i] == ')'){
                count -= 1;
            }

            maxDepth = max(maxDepth, count);
        }

        return maxDepth;
    }
};
