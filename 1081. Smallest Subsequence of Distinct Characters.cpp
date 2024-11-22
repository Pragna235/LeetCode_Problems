class Solution {
public:
    string smallestSubsequence(string s) {
    int n = s.size();
    string ans = "";
    vector<bool> taken(27 , false);
    vector<int> lastOcc(27 , 0);
    for(int i = 0 ; i< n ; i++){
        lastOcc[s[i] - 'a'] = i ; 
    }
    for(int i = 0 ; i< n ; i++){
        if(taken[s[i] - 'a']) continue;
        if(ans.size()== 0 || ans.back() <s[i]){
            ans+= s[i];
            taken[s[i] - 'a'] = true;
        }
        else{
            while(ans.size()>0 && ans.back()>s[i] && lastOcc[ans.back()-'a'] > i){
             
                taken[ans.back()-'a'] = false;
                   ans.pop_back() ;
            }
          ans+= s[i];
          taken[s[i] - 'a'] = true;
        }
    }
    return ans;
    
 
    }
};
