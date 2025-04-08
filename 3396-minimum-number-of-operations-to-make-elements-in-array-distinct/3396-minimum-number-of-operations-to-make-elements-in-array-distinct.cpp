class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freqs;

        for(int num : nums) {
            freqs[num] += 1;
        }

        priority_queue<pair<int, int>> pq;

        for(auto& [val, freq] : freqs) {
            pq.push({freq, val});
        }

        vector<int> reduces(101, 0);
        int res = 0;

        for(int i = 0; i < nums.size(); i += 3) {
            if(pq.top().first <= 1) break;

            for(int j = i; j < i + 3 && j < nums.size(); j++) {
                reduces[nums[j]] -= 1;
            }
            
            res++;

            while(!pq.empty()) {
                if(pq.top().first + reduces[pq.top().second] <= 1) pq.pop();
                else break;
            }

            if(pq.empty()) break;
        }

        return res;
    }
};