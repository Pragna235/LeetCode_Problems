class Solution:
    def countBits(self, n: int) -> List[int]:
        #count=0
        ans=[0]
        for i in range(1,n+1):
            count=0
            while(i!=0):
                if((i&1)==1):
                    count+=1
                i=i>>1
            ans.append(count)
        return ans
