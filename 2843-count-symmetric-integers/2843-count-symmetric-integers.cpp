class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++) {
            string numStr = to_string(i);

            if(numStr.size() == 2 && numStr[0] == numStr[1]) res++;
            else if(numStr.size() == 4) {
                if(numStr[0] - '0' + numStr[1] - '0' == numStr[2] - '0' + numStr[3] - '0') res++;
            }
        }
        return res;
    }
};