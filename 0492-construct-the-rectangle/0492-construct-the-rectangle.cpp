class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> LW;
        for(int i = sqrt(area); i >= 1 ; i--) {
            if(area % i == 0) {
                LW.push_back(max(i, area / i));
                LW.push_back(min(i, area / i));
                break;
            }
        }
        return LW;
    }
};