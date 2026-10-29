class Solution {
public:
    int calc(vector<int>& s1, vector<int>& d1,
             vector<int>& s2, vector<int>& d2) {

        int firstEnd = INT_MAX;

        for (int i = 0; i < s1.size(); i++) {
            firstEnd = min(firstEnd, s1[i] + d1[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < s2.size(); i++) {
            ans = min(ans, max(firstEnd, s2[i]) + d2[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int a = calc(landStartTime, landDuration,
                     waterStartTime, waterDuration);

        int b = calc(waterStartTime, waterDuration,
                     landStartTime, landDuration);

        return min(a, b);
    }
};