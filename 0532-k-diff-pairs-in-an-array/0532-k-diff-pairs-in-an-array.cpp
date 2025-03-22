class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int res = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int another =  nums[i] + k;
            
            if(um.count(another) && another == nums[i] && um[another] > 1) res++;
            else if(um.count(another) && another != nums[i]) res++;
        }

        return res;
    }
};