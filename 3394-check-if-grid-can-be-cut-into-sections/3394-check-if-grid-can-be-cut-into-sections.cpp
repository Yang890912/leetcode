class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xs;
        vector<vector<int>> ys;

        for(int i = 0 ; i < rectangles.size(); i++) {
            vector<int> vecX, vecY;
            vecX.push_back(rectangles[i][0]);
            vecX.push_back(rectangles[i][2]);
            xs.push_back(vecX);
            vecY.push_back(rectangles[i][1]);
            vecY.push_back(rectangles[i][3]);
            ys.push_back(vecY);
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int lines = 0;
        int curr = xs[0][1];
        for(int i = 1 ; i < xs.size(); i++) {
            if(xs[i][0] < curr) {
                curr = max(curr, xs[i][1]);
                continue;
            }
            curr = max(curr, xs[i][1]);
            lines++;
            if(lines >= 2) return true;
        }
        lines = 0;
        curr = ys[0][1];
        for(int i = 1 ; i < ys.size(); i++) {
            if(ys[i][0] < curr) {
                curr = max(curr, ys[i][1]);
                continue;
            }
            curr = max(curr, ys[i][1]);
            lines++;
            if(lines >= 2) return true;
        }

        return false;
    }
};