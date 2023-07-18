class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
        return false;
        int a = log(n)/log(4);
        if(n==pow(4,a))
        return true;
        return false;
    }
};
