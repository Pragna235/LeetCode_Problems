class Solution:
  def plusOne(self, digits: List[int]) -> List[int]:
    st=map(str,digits)
    st=list(st)
    t=""
    for i in st:
      t=t+i
    t=int(t)+1
    t=str(t)
    k=[]
    for i in t:
      k.append(int(i))
    return k
