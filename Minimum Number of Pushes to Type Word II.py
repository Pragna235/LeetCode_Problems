class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = Counter(word)
        freq = Counter(word)
        cur = 1
        ans = 0
        for x in sorted(cnt.values(), reverse=True):
            freq[cur] += 1
            ans += x * cur
            if freq[cur] == 8: cur += 1
        return ans
