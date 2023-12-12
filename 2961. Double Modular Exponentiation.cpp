class Solution {
public:
    
    long long powMod(long long base, long long exp, long long mod){
        long long res=1;
        while(exp>0){
            if(exp%2==1){
                res = (res*base)%mod;
            }
            base = (base * base)%mod;
            exp/=2;
        }
        return res;
    }
        
        
        
        
        
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n = variables.size();
        vector<int> result;
            
        for(int i=0;i<n;i++){
            
            long long r1 = powMod(variables[i][0], variables[i][1],10);
            long long r2 = powMod(r1, variables[i][2], variables[i][3]);
            
            
            if(r2 == target)
                result.push_back(i);
        }
        return result;
        
    }
};
