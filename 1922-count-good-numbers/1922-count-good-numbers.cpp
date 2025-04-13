class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodNumbers(long long n) {
        long long even = 0;
        long long odd = 0;
        long long res;

        even = (n % 2 == 0) ? n / 2 : n / 2 + 1;
        odd = n / 2;

        res = calPermu(5, even) * calPermu(4, odd) % MOD;

        return res;
    }

    long long calPermu(int base, long long exponent) {
        if(exponent == 0) return 1;
        else if(exponent == 2) return base * base % MOD;

        long long res = calPermu(base, exponent / 2);

        if(exponent % 2 == 0) res = res * res % MOD;
        else res = res * res * base % MOD;

        return res;
    }
};