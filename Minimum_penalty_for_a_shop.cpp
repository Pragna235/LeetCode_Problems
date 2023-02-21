class Solution {
public:
    int bestClosingTime(string customers) {
        int c=customers.size(),t1=c,t2=-1;
        vector<int> list(c+1);
        for(int i=0;i<c;i++)
        {
            list[i+1]=list[i]+(customers[i]=='Y');
        }

        for(int i=0;i<=c;i++)
            if(i-list[i]+list[c]-list[i]<t1)
        {
            t1=i-list[i]+list[c]-list[i];
            t2=i;
        }
        return t2;
    }


};
