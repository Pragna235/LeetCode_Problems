class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        if x > y: x, y = y, x
        ans = [0] * (n + 1)
        x -= 1
        y -= 1
        for i in range(n):
            if abs(i - x) + 1 > abs(i - y):
                ans[1] += 1
                ans[n - i] -= 1
            else:
                d = abs(i - x) + 1
                sep = i + d + (y - i - d) // 2
                ans[1] += 1
                ans[sep - i + 1] -= 1
                ans[d + 1] += 1
                ans[d + y - sep] -= 1
                ans[d] += 1
                ans[d + n - y] -= 1
        ans = list(accumulate(ans))
        return [x * 2 for x in ans[1:]]
