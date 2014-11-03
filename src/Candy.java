//http://www.2cto.com/kf/201402/278629.html
public class Solution {
    public int candy(int[] ratings) {
        if (ratings == null || ratings.length <= 0) {
            return 0;
        }
 
        int ret = 0;
        int N = ratings.length;
        int[] candy = new int[N];
        candy[0] = 1;
        for (int i = 1; i < N; ++i) {
            candy[i] = 1;
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        ret = candy[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = Math.max(candy[i], candy[i + 1] + 1);
            }
            ret += candy[i];
        }
        return ret;
    }
}
