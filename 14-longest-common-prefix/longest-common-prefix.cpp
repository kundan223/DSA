class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        sort(strs.begin(), strs.end());

        int n = strs.size();
        string first = strs[0];
        string last = strs[n - 1];

        for (int k = 0; k < min(first.length(), last.length()); k++) {

            if (first[k] == last[k]) {
                ans += first[k];
            } else {
                return ans;
            }
        }

        return ans;
    }
};
