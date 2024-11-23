class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string str = "";
        string count = "";

        for(int i = 0; i < s.length(); i++){
            if(s[i] == ']'){

                // Collect the string inside the brackets
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }

                // Pop the '[' character
                st.pop();

                // Collect the numbers
                while(!st.empty() && isdigit(st.top())){
                    count = st.top() + count;
                    st.pop();
                }

                // Convert count to integer
                int c = stoi(count);
        
                while(c--){
                    // Push the decoded substring back onto the stack
                    for(char it : str){
                        st.push(it);
                    }
                }
                str = "";
                count = "";
            }
            else{
                st.push(s[i]);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
