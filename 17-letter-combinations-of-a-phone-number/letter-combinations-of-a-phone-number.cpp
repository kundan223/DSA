class Solution {
public:

    void backtrack(int index, string digits, vector<string>& ans, string temp, unordered_map<char, string>& mp) {

        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[index]];

        for (int k = 0; k < letters.size() ; k++) {
            temp.push_back(letters[k]); // fixed variable name + syntax
            backtrack(index + 1, digits, ans, temp, mp);
            
            temp.pop_back(); // fixed pop
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.size() == 0) return ans;

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        string temp = "";

        backtrack(0, digits, ans, temp, mp);

        return ans;
    }
};