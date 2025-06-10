class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        string s = to_string(n);
        dfs(s, 0, "", res);
        return res;
    }

    void dfs(string s, int idx, string prevStr, vector<int>& res) {
        for(char i = '0'; i <= '9'; i++) {
            string currStr = prevStr + i;

            if(i == '0' && idx == 0) continue;
            if(stoi(currStr) > stoi(s)) return;

            res.push_back(stoi(currStr));

            if(idx + 1 < s.size()) dfs(s, idx + 1, currStr, res);
        }
    }
};