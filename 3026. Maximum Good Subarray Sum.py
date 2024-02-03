class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        d = {}
        cur = 0
        res = -10 ** 18
        
        for i in nums:
            d[i] = min(d.get(i, 10 ** 20), cur)

            cur += i
            if i - k in d:
                res = max(res, cur - d[i - k])
            if i + k in d:
                res = max(res, cur - d[i + k])
            
        
        if res == -10 ** 18:
            res = 0
        return res
