class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        res=[]
        for i in range(n):
            complement=target-nums[i]
            if((complement in nums) and (i != nums.index(complement))):
                res.append(i)
                res.append(nums.index(complement))
                break
        return res
            
