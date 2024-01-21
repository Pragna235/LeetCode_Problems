class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        result = [0] * n
    
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                distance = min(abs(j - i), abs(x - i) + 1 + abs(j - y),abs(y - i) + 1 + abs(j - x))
                result[distance - 1] += 1
        for i in range(n):
            result[i] *= 2
                
         
    
        return result
    
    
        
        
            
        
        
    
        
        
        
