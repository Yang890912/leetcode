class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = sqrt(INT_MAX);

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(num % mid == 0 && num == mid * mid) return true;
            else if(num > mid * mid) left = mid + 1;
            else if(num < mid * mid) right = mid - 1;
        }

        return false;
    }
};