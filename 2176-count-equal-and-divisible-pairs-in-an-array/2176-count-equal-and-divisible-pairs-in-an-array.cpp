class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> um;
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(um.count(nums[i]) == 0) {
                um[nums[i]] = {i};
            }
            else {
                for(int j = 0; j < um[nums[i]].size(); j++) {
                    if(um[nums[i]][j] * i % k == 0) res++;
                }
                um[nums[i]].push_back(i);
            }
        }

        return res;
    }
};