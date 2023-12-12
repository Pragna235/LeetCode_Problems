class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        last = {x : i for i, x in enumerate(nums)}
        ii = p = -1
        for i, x in enumerate(nums): 
            if ii < i: p += 1
            ii = max(ii, last[x])
        return pow(2, p, 1_000_000_007)
