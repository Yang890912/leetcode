class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int remainDays = 0;
        sort(meetings.begin(), meetings.end());

        for(int i = 0; i < meetings.size(); i++) {
            if(i == 0) remainDays += meetings[i][0] - 1;
            else remainDays += max(0, meetings[i][0] - meetings[i - 1][1] - 1);
            
            if(i == meetings.size() - 1) remainDays += max(0, days - meetings[i][1]); 
        }

        return remainDays;
    }
};