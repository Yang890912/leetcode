class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] % 2 == 0) res[i++] = 0;
        }
        return res;
    }
};