class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        if(n<9):
            sum=n
        elif(n<16):
            sum =8+ ((n-8)*2 )
        elif(n<25):
            sum =8 +16+ ((n-16)*3)
        else:
            sum = 8+16+24+((n-24)*4)
        return sum
            
        
