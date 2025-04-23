class Solution {
public:
    int countLargestGroup(int n) {
        int currMaxSize = 0;
        int res = 0;
        vector<int> counts(37, 0);

        for(int i = 1; i <= n; i++) {
            int sum = 0;
            int x = i;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            counts[sum] += 1;
            currMaxSize = max(currMaxSize, counts[sum]);
        }

        for(int i = 1; i < counts.size(); i++) {
            if(counts[i] == currMaxSize) res++;
        }

        return res;
    }
};