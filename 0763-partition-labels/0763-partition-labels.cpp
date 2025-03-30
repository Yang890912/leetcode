class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        vector<int> res;

        for(int i = s.size() - 1; i >= 0 ; i--) {
            if(last[s[i] - 'a'] < i) last[s[i] - 'a'] = i;
        }

        int i = 0;
        while(i < s.size()) {
            int currLast = last[s[i] - 'a'];
            for(int j = i; j <= currLast; j++) {
                if(last[s[j] - 'a'] > currLast) currLast = last[s[j] - 'a'];
            }
            res.push_back(currLast - i + 1);
            i = currLast + 1;
        }

        return res;

    }
};