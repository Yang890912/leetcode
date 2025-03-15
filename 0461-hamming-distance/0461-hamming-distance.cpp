class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int dist = 0;
        while(z) {
            if(z & 1) dist++;
            z = z >> 1;
        }
        return dist;
    }
};