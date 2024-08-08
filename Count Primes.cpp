class Solution {
public:
    int N=5*1e6+5;
    int sieve(int n)
    {
        bool is_prime[N];
        fill(is_prime, is_prime + N, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2;i*i<n; i++) 
        {                            
            if (is_prime[i])
            {
                for (int j = i*i;j<n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }
        int num=0;
        for (int i = 2;i<n; i++) 
            if(is_prime[i])
                 num++;
        return num;
    }
    int countPrimes(int n) {
        return sieve(n);
    }
};
