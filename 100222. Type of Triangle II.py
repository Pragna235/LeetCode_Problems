class Solution(object):
    def triangleType(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        yes=0
        
        if(yes==0):
            if((nums[0]+nums[1])>nums[2]):
                yes+=1
            if((nums[0]+nums[2])>nums[1]):
                yes+=1
            if((nums[1]+nums[2])>nums[0]):
                yes+=1
        
            
        if(yes==3):
            if(len(set(nums)) == 1):
                return "equilateral"
            elif(len(set(nums)) == 2):
                return "isosceles"
            else:
                return "scalene"
        else:
            return "none"
        
