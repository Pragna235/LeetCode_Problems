class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res, temp = "", ""

        is_rev = True
        count = 0
        for i in s:
            count += 1
            if is_rev:
                temp = i + temp
            else:
                temp = temp + i

            if count == k:
                res = res + temp
                temp = ""
                count = 0
                is_rev = not is_rev
        res += temp
        return res
