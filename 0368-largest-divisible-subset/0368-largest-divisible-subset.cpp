class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        int largest = 0;
        int largestIdx = 0;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] % nums[i] == 0 && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    prev[j] = i;
                    if(dp[j] > largest) {
                        largest = dp[j];
                        largestIdx = j;
                    }
                }
            }
        }

        vector<int> res;
        while(largestIdx != -1) {
            res.push_back(nums[largestIdx]);
            largestIdx = prev[largestIdx];
        }

        return res;
    }
};