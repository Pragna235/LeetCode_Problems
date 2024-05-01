class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int idx = -1;

        for(int i=0;i<n;i++){
            if(word[i] == ch){
                idx = i;
                break;
            }
            
        }
        if(idx != -1){
            //cout<<idx<<endl;
            string tbrev = word.substr(0,idx+1);
            string remaining = word.substr(idx+1,n-idx);
            //cout<<idx<<" "<<to_be_reversed<<endl;
            //cout<<remaining<<endl;
            reverse(tbrev.begin(),tbrev.end());
            string result = tbrev+remaining;
            return result;
        }
        
        

        return word;
        
    }
};
