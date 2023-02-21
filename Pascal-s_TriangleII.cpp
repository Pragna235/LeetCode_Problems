class Solution {
    public List<Integer> getRow(int rowIndex) {
        Integer[] result = new Integer[rowIndex+1];
        result[0]=1;
        for(int r=1;r<=rowIndex;r++)
        {
            result[r] = (int)(((long)result[r-1]*(rowIndex-r+1))/(r));

        }
        return Arrays.asList(result);

    }
}
