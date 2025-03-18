class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int currPos = start;
        int currGas = 0;

        while(start < gas.size()) {
            currGas += gas[currPos % gas.size()];
            currGas -= cost[currPos % gas.size()];

            if(currGas < 0) {
                currGas = 0;
                start = currPos + 1;
                currPos = start;
                continue;
            }

            currPos++;

            if(currPos % gas.size() == start) return start;
        }

        return -1;
    }
};