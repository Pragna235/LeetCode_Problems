class Solution {
public:
    int isPowerOfTwo(int n) {
        if(n==0) return false;
        if(ceil(log2(n)) == floor(log2(n)))
        return true;
        return false;
    }
};
