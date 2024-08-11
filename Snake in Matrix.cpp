class Solution {
public:
    int finalPositionOfSnake(int z, vector<string>& commands) {
        int n = commands.size();
        int i=0,j=0;
        for(int k=0;k<n;k++){
            if(commands[k]=="UP"){
                i--;
            }
            else if(commands[k]=="DOWN"){
                i++;
            }
            else if(commands[k]=="LEFT"){
                j--;
            }
            else{
                j++;
            }
        }
        return (i*z)+j;
    }
};
