class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) x = 1 / x;
    
        long N = labs(n);  
        double res = 1;

        while(N) {
            if((N & 1) == 1) {
                res *= x;
            }

            x *= x;
            N >>= 1;
        }

        return res;
    }
};