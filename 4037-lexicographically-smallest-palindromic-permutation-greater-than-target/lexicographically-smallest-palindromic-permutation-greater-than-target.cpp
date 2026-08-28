class Solution {
public:

    string makePalindrome(string left, char middle) {
        string right = left;
        reverse(right.begin(), right.end());

        if (middle == '\0') {
            return left + right;
        }

        return left + string(1, middle) + right;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int cnt[26] = {0};

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        char middle = '\0';
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        for (int i = 0; i < 26; i++) {
            cnt[i] /= 2;
        }

        int half = n / 2;
        string targetLeft = target.substr(0, half);

        int temp[26];
        string left = "";

        for (int i = 0; i < 26; i++) {
            temp[i] = cnt[i];
        }

        bool possible = true;

        for (int i = 0; i < half; i++) {
            int x = targetLeft[i] - 'a';

            if (temp[x] == 0) {
                possible = false;
                break;
            }

            left += targetLeft[i];
            temp[x]--;
        }

        if (possible) {
            string answer = makePalindrome(left, middle);

            if (answer > target) {
                return answer;
            }
        }

        for (int change = half - 1; change >= 0; change--) {

            for (int i = 0; i < 26; i++) {
                temp[i] = cnt[i];
            }

            string newLeft = "";
            bool okay = true;

            for (int i = 0; i < change; i++) {
                int x = targetLeft[i] - 'a';

                if (temp[x] == 0) {
                    okay = false;
                    break;
                }

                newLeft += targetLeft[i];
                temp[x]--;
            }

            if (!okay) {
                continue;
            }

            int wanted = targetLeft[change] - 'a';
            int bigger = -1;

            for (int c = wanted + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1) {
                continue;
            }

            newLeft += char('a' + bigger);
            temp[bigger]--;

            for (int c = 0; c < 26; c++) {
                while (temp[c] > 0) {
                    newLeft += char('a' + c);
                    temp[c]--;
                }
            }

            return makePalindrome(newLeft, middle);
        }

        return "";
    }
};