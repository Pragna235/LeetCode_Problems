class Solution {
public:
    string reverseWords(string s) {
        if(s =="" || s==" "){
            return s;
        }
        string ans;
        int start = s.length()-1;
        while(start>=0){
            if(s[start]==' '){
                start--;
            }
            else{
                if(ans.length()>0){
                    ans.push_back(' ');
                }
                int j=start;
                while(j>=0 && s[j]!=' '){
                    j--;
                }
                ans.append(s.substr(j+1,start-j));
                start=j;
            }
        }
        return ans;
    }
};
