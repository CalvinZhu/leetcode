//http://blog.csdn.net/doc_sgl/article/details/13418125
class Solution {
public:
int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.size();
		int* dp = new int[len+1];
		for(int i=len; i>=0; i--)
			dp[i] = len-i;
		bool** matrix = new bool*[len];
		for(int i=0; i<len; i++)
		{
			matrix[i] = new bool[len];
			memset(matrix[i], false, sizeof(bool)*len);
		}
		for(int i=len-1; i>=0; i--)
			for(int j=i; j<len; j++)
			{
				if(s[i] == s[j] && (j-i<2 || matrix[i+1][j-1]))
				{
					matrix[i][j] = true;
					dp[i] = min(dp[i], dp[j+1]+1);
				}
			}
		return dp[0]-1;
    }
};
