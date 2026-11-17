class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i : nums) {
            mp[i]++;
        }

        priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
            [&](int a, int b) { // make it simple i cant understant what this [&] is and ina and b is 
                return mp[a] < mp[b]; // what is this condition and why are we returning something here 
            }
        );

        for(auto it : mp) { // we pusing the things in the heap 
            maxHeap.push(it.first); // how are we making sure it take into account the frequency and not the actual valie 
        }

        vector<int> res(k);

        for(int i = 0; i < k; i++) {
            res[i] = maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }
};