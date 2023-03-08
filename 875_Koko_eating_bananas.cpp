class Solution {
public: bool ok(vector<int>& piles,int mid,int h){
    int count=0;
    for(int i=0;i<piles.size();++i){
        double temp=(double)piles[i]/(double)mid;

        if(temp>(int)temp){
            count+=(int)temp+1;
        }
        else{
            count+=temp;
        }

    }
    if(count>h){
           return false;
       }else{
           return true;
       }
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid;
        int left=1;
        int right=1e9+5;
        int ans=0;
        while(left<right){
            mid=left+(right-left)/2;
            if(ok(piles,mid,h)){
              ans=mid;
              right=mid;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
