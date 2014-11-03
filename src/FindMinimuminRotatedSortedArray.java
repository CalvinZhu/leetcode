public class Solution {
    public int findMin(int[] num) {
        int min = num[0];
        for (int i=1;i<num.length;i++)
        {
            if(min>num[i])
                min = num[i];
        }
        return min;
    }
}
