class Solution {
public:
    string removeDuplicateLetters(string s) {
         vector<int>f(26,0);
				vector<int>vs(26,0);
				stack<char>st;
				for(auto it:s) f[it-'a']++;
				for(int i=0;i<s.length();i++)
				{
        char ch=s[i];
				// first dece the frq of char && mark is true and false
        f[ch-'a']--;
				if (vs[ch-'a']) continue;
				// remove the the which is not miantin curr char
   while(!st.empty() && st.top()>ch && f[st.top()-'a']>0)
	   {
      vs[st.top()-'a']--;
			st.pop();
     }
		 // Add the current char
   vs[ch-'a']++;
	 st.push(ch);
				}
				string str="";
				while(!st.empty()){
					str+=st.top();
					st.pop();
				}
   	reverse(str.begin(),str.end());
   	return str;
    }
};
