class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int res = 0;

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n - 1; k++) {
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        res++;
                }
            }
        }

        return res;
    }
};