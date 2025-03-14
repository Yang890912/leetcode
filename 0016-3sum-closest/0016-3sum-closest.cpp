class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 100000;

        for(int i = 0; i < nums.size(); i++) {
            int newTarget = target - nums[i];
            int left = 0;
            int right = nums.size() - 1;
            while(left < right) {
                if(left == i) left++;
                else if(right == i) right--;
                else if(nums[left] + nums[right] > newTarget) {
                    if(abs(sum - target) > abs(nums[left] + nums[right] - newTarget)) 
                        sum = nums[left] + nums[right] + nums[i];
                    right--;
                }
                else if(nums[left] + nums[right] < newTarget) {
                    if(abs(sum - target) > abs(nums[left] + nums[right] - newTarget))
                        sum = nums[left] + nums[right] + nums[i];
                    left++;
                }
                else if(nums[left] + nums[right] == newTarget) {
                    return target;
                }
            }
        }

        return sum;
    }
};