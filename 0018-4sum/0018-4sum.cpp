class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> us;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 3; j < nums.size(); j++) {
                int left = i + 1;
                int right = j - 1;
                long long newTarget = target - nums[i] - nums[j];

                while(left < right) {
                    if(nums[left] + nums[right] > newTarget) right--;
                    else if(nums[left] + nums[right] < newTarget) left++;
                    else {
                        vector<int> vec = {nums[i], nums[left], nums[right], nums[j]};
                        us.insert(vec);
                        left++;
                        right--;
                    }
                }
            }
        }

        vector<vector<int>> res;
        for (const auto& vec : us) {
            res.push_back(vec);
        }
        return res;
    }
};