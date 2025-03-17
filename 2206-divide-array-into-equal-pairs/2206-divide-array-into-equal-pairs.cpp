class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> numOfNumber(501, 0);

        for(int i = 0; i < nums.size(); i++) {
            numOfNumber[nums[i]]++;
        }

        for(int i = 0; i < 501; i++) {
            if(numOfNumber[i] % 2 == 1) return false;
        }

        return true;
    }
};