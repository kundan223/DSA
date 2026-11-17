
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // Min heap: {sum, {i, j}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        // Insert the first pair from each row
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- && !pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int i = p.second.first;
            int j = p.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // Move to the next element in the same row
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
