class Solution {
public:

    void computeLPSArray(string &s, int m,vector<int> &lps){
        int len=0;
        lps[0]=0;
        //int m = lps.size();
        int i=1;
        while(i<m){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }

    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        if(s.length()==1) return false;
        
        vector<int> lps(m,0);
        computeLPSArray(s,m,lps);

        for(int i=0;i<m;i++){
            cout<<lps[i]<<" ";
        }

        if(m%(m-lps[m-1]) == 0 && lps[m-1]!=0) return true;
        return false;
    }
};
