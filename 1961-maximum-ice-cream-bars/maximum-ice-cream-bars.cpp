class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> v(100001, 0);

        for (int i = 0; i < costs.size(); i++) {
            v[costs[i]]++;
        }

        int ans = 0;

        for (int i = 1; i <= 100000; i++) {
            while (v[i] > 0 && coins >= i) {
                coins -= i;
                ans++;
                v[i]--;
            }
        }

        return ans;
    }
};