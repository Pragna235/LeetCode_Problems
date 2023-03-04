class Solution {
public:
    bool isPalindrome(int x) {
        long long int sum=0,rem,y=x;
        while(x>0)
        {
             rem=x%10;
             x=x/10;
            sum=rem+(10*sum);
        }
        if(y==sum)
        return true;
        else
        return false;


    }
};
