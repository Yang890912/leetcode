class Solution {
public:
    bool repeatedSubstringPattern(string s) {
            
        for(int i = 1; i < s.size() / 2 + 1; i++) {
            string sub = s.substr(0, i);
            string repeated = sub;

            while(repeated.size() < s.size()) repeated += sub;

            if(repeated == s) return true;
        }
        
        return false;
    }
};