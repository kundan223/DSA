
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        long long limit = k + n + 1;
        vector<long long> len(n + 1, 0);

        // Forward pass
        for (int i = 0; i < n; i++) {
            long long x = len[i];

            if (s[i] >= 'a' && s[i] <= 'z') {
                len[i + 1] = min(limit, x + 1);
            }
            else if (s[i] == '*') {
                len[i + 1] = max(0LL, x - 1);
            }
            else if (s[i] == '#') {
                len[i + 1] = min(limit, x * 2);
            }
            else {
                len[i + 1] = x;
            }
        }

        if (k >= len[n]) return '.';

        // Backward pass
        bool fromRight = false;
        long long pos = k;

        for (int i = n - 1; i >= 0; i--) {
            long long prev = len[i];

            if (s[i] >= 'a' && s[i] <= 'z') {
                if (fromRight) {
                    if (pos == 0) return s[i];
                    pos--;
                }
                else {
                    if (pos == prev) return s[i];
                }
            }
            else if (s[i] == '*') {
                if (fromRight) {
                    pos++;
                }
            }
            else if (s[i] == '#') {
                if (prev > 0) {
                    pos %= prev;
                }
            }
            else if (s[i] == '%') {
                fromRight = !fromRight;
            }
        }

        return '.';
    }
};
