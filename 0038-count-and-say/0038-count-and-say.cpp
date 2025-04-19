class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        return vecToStr(strToVec(countAndSay(n - 1)));
    }

    vector<pair<int, int>> strToVec(string s) {
        vector<pair<int, int>> vec;
        int freq = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i == 0 || s[i - 1] == s[i]) freq++;
            else {
                vec.push_back({freq, s[i - 1] - '0'});
                freq = 1;
            }
        }
        vec.push_back({freq, s[s.size() - 1] - '0'});
        return vec;
    }

    string vecToStr(vector<pair<int, int>> vec) {
        string s = "";
        for(int i = 0; i < vec.size(); i++) {
            s += to_string(vec[i].first);
            s += to_string(vec[i].second);
        }
        return s;
    }

    
};