class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        print(word,ch)
        if(ch in word):
            id = word.index(ch)
            #print(id)
            reversed = word[0:id+1]
            #print(reversed)
            rev = reversed[::-1]
            #print(rev)
            rem = word[id+1:]
            #print(rem)
            result = rev+rem
            #print(result)
            return result
        return word
        
        
