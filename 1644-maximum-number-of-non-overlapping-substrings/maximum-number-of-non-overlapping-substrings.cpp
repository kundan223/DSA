class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = i;
        }

        vector<pair<int, int>> sub;

        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a'])
                continue;

            int left = i;
            int right = last[s[i] - 'a'];
            bool ok = true;

            for (int j = left; j <= right; j++) {
                int x = s[j] - 'a';

                if (first[x] < left) {
                    ok = false;
                    break;
                }

                right = max(right, last[x]);
            }

            if (ok) {
                sub.push_back({left, right});
            }
        }

        sort(sub.begin(), sub.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int lastEnd = -1;

        for (auto [left, right] : sub) {
            if (left > lastEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                lastEnd = right;
            }
        }

        return ans;
    }
};