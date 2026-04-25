class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0) return false;

        priority_queue<int, vector<int>, greater<int>> pq;

        unordered_map<int, int> freq;

        for (int x : hand) {
            freq[x]++;
            pq.push(x);
        }

        while (!pq.empty()) {

            int start = pq.top(); 

            for (int i = 0; i < groupSize; i++) {

                int curr = start + i;

                if (freq[curr] == 0) {
                    return false;
                }

                freq[curr]--;

                while (!pq.empty() && freq[pq.top()] == 0) {
                    pq.pop();
                }
            }
        }

        return true;
    }
};