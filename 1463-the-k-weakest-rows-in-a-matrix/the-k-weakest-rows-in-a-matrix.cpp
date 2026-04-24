
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // min heap: (soldiers, index)
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
        > pq;

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            int count = 0;

            // count soldiers in row
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) count++;
                else break; // because sorted
            }

            pq.push({count, i});
        }

        vector<int> result;

        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};