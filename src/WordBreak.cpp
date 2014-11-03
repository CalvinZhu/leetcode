//http://blog.csdn.net/a83610312/article/details/12870501
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = (int)s.size();
		vector<bool> dp(n + 1, false);
		dp[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(dp[i-1])
			{
				int idx=i-1;
				for(int j=idx;j<n;j++)
				{
					string cur=s.substr(idx,j-idx+1);
					if(dict.count(cur)>0)
						dp[j+1]=true;
				}
			}
		}
		return dp[n];
	}
};
