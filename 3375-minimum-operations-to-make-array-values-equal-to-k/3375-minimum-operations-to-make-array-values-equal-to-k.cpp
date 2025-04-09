class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int currMin = INT_MAX;
        unordered_set<int> us;

        for(int& num : nums) {
            us.insert(num);
            currMin = min(currMin, num);
        }

        if(k > currMin) return -1;
        else if(k == currMin) return us.size() - 1;
        else return us.size();
    }
};