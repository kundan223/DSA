class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int sum = 0, maxWeight = 0;

        for (int w : weights) {
            sum += w;
            maxWeight = Math.max(maxWeight, w);
        }

        int l = maxWeight, r = sum;
        int ans = sum;

        while (l <= r) {
            int cap = l + (r - l) / 2;
            int usedDays = 1;
            int currSum = 0;

            for (int w : weights) {
                if (currSum + w > cap) {
                    usedDays++;
                    currSum = 0;
                }
                currSum += w;
            }

            if (usedDays <= days) {
                ans = cap;
                r = cap - 1;
            } else {
                l = cap + 1;
            }
        }
        return ans;
    }
}