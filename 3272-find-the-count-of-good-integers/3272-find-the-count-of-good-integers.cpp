class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long res = 0;
        unordered_map<string, bool> numMap;
        string num(n, ' ');

        genPalindrome(n, k, 0, num, numMap, res);
        
        return res;
    }

    void genPalindrome(int n, int k, int idx, string& num, unordered_map<string, bool>& numMap, long long& res) {
        for(char c = '0'; c <= '9'; c++) {
            if(idx == 0 && c == '0' && n > 1) continue;

            num[idx] = c;
            num[n - idx - 1] = c;

            if(idx == (n - 1) / 2) {
                long long tmpNum = stoll(num);

                if(tmpNum % k != 0) continue;

                string tmpStrNum = num;
                sort(tmpStrNum.begin(), tmpStrNum.end());

                if(numMap[tmpStrNum]) continue;

                res += calPermutations(tmpStrNum);
                numMap[tmpStrNum] = true;
            }
            else {
                genPalindrome(n, k, idx + 1, num, numMap, res);
            }
        }
    }

    long long calPermutations(string num) {
        int n = num.size();
        long long res = 0;
        vector<int> freq(10, 0);

        for(int i = 0; i < n; i++) {
            freq[num[i] - '0']++;
        }

        res = factorial(n);
        for(int i = 0; i < 10; i++) {
           res /= factorial(freq[i]);
        }

        if(freq[0] >= 1) {
            long long tmp = factorial(n - 1);
            for(int i = 0; i < 10; i++) {
                tmp /= (i == 0) ? factorial(freq[i] - 1) : factorial(freq[i]);
            }
            res -= tmp;
        }
        return res;
    }

    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
};