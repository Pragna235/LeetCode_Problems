from functools import cmp_to_key
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        chord = dict()
        for i in range(len(order)):
            chord[order[i]] = i
        
        def compare(b, a):
            
            for i in range(min(len(a), len(b))):
                if a[i] in chord and b[i] in chord:
                    if chord[a[i]] < chord[b[i]]:
                        return 1
                    elif chord[a[i]] == chord[b[i]]:
                        continue
                    else:
                        return -1
                else:
                    return -1
            return 1 if len(a) < len(b) else -1

        return sorted(words, key=cmp_to_key(compare)) == words
        
        
