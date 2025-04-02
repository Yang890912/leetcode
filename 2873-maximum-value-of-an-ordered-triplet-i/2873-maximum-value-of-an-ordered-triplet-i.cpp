class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> Rmax(n, 0);
        vector<long long> Lmax(n, 0);

        Lmax[0] = max((int)Lmax[0], nums[0]);
        Rmax[n - 1] = max((int)Rmax[n - 1], nums[n - 1]);
        for(int i = 1; i < n - 1; i++) {
            Lmax[i] = max((int)Lmax[i - 1], nums[i]);
            Rmax[n - i - 1] = max((int)Rmax[n - i], nums[n - i - 1]);
        }

        long long res = 0;
        for(int j = 1; j < n - 1; j++) {
            res = max(res, (Lmax[j - 1] - nums[j]) * Rmax[j + 1]);
        }

        return res;
    }
};