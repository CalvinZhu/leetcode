//http://blog.csdn.net/a83610312/article/details/12870501
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) 
	{
		int n=s.length();
		vector<vector<bool> > match(n+1,vector<bool>(n+1,false));
		for(int i=0;i<=n;i++)
			match[0][i]=true;
		for(int len=1;len<=n;len++)
		{
			for(int start=0;start+len<=n;start++)
			{
				string tmp=s.substr(start,len);
				if(dict.count(tmp)>0)
					match[len][start]=true;
				else
				{
					for(int left=1;left<len;left++)
					{
						match[len][start]=match[left][start]&&match[len-left][start+left];
						if(match[len][start])
							break;
					}
				}
			}
		}
		if(match[n][0]==false)
			return vector<string>();
		vector<string> ans;
		vector<string> had;
		dfs(s,0,match,had,ans,dict);
		return ans;
	}
	void dfs(string& s,int k,vector<vector<bool> >& match,vector<string>& had,vector<string>& ans,unordered_set<string> &dict)
	{
		int n=s.length();
		if(k>=n)
		{
			if(!had.empty())
			{
				string ret;
				for(int i=0;i<had.size();i++)
				{
					ret.append(had[i]);
					if(i!=had.size()-1)
						ret.push_back(' ');
				}
				ans.push_back(ret);
				return;
			}
		}
		for(int len=1;k+len<=n;len++)
		{
			string tmp=s.substr(k,len);
			if(dict.count(tmp)>0 && match[n-k-len][k+len])
			{
				had.push_back(tmp);
				dfs(s,k+len,match,had,ans,dict);
				had.pop_back();
			}
		}
	}	
};
