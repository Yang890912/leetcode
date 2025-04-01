class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);

        return rec(questions, 0, dp);
    }

    long long rec(const vector<vector<int>> questions, int pos,  vector<long long>& dp) {
        if(pos >= questions.size()) return 0;
        
        if(dp[pos] != -1) return dp[pos];

        long long select = questions[pos][0] + rec(questions, pos + questions[pos][1] + 1, dp);
        long long usSelect = rec(questions, pos + 1, dp);

        dp[pos] = max(select, usSelect);

        return dp[pos];
    }
};