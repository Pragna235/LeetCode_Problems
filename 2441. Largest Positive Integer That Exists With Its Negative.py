class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        result = []
        for i in nums:
            if((-i) in nums):
                #print(i,-i)
                result.append(i)
        #print(result)
        if(len(result)):
            return max(result)
        return -1
        
