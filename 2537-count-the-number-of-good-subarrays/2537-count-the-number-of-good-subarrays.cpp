class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        long long res = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;

        long long tmp = 0;
        
        while(left <= right && right < n) {
            um[nums[right]]++;
            tmp += um[nums[right]] - 1;

            while(tmp >= k) {
                res += (n - right);
                um[nums[left]]--;
                tmp -= um[nums[left]];
                left++;
            }

            right++;
        }

        return res;
        
    }
};