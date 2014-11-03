/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
//http://www.cnblogs.com/dolphin0520/p/3737561.html
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxNum =0;
        int size = points.size();
        int i,j;
        if(size <=2)   //如果点的个数小于3个，则最大数目为点的个数 
            return size;
        for(i=0;i<size;i++)
        {
            int cnt =0;
            map<double,int> mp;
            for(j=0;j<size;j++)
            {
                if(i==j)
                    continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    cnt++;
                    continue;
                }   
                //注意当直线与y轴平行的情况 
                double slope = points[i].x == points[j].x ? INT_MAX : (double)(points[j].y - points[i].y)/(points[j].x - points[i].x);  
                mp[slope]++;  
            }
             
            if(mp.size()==0)   //防止mp为空时，下面的for循环不执行 
                mp[INT_MIN] =0;
            map<double,int>::iterator it = mp.begin();
            for(;it!=mp.end();it++)
            {
                if(it->second+ cnt > maxNum)
                    maxNum = it->second +cnt;
            }
        }
        return maxNum+1;
    }
};
