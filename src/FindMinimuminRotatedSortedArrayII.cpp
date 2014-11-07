//http://blog.csdn.net/xiaoxiaoluo/article/details/40632243
class Solution {
public:
        int findMin(vector<int> &num) {  
            return assistFindMin(num, 0, num.size() - 1);  
        }  
          
private:  
        int assistFindMin(vector<int> &num, int begin, int end) {  
            if(begin == end || num[begin] < num[end])  
              return num[begin];  
            int mid = (begin + end) >> 1;  
            if(num[mid] > num[begin])  
              return assistFindMin(num, mid + 1, end);  
            else if(num[mid] < num[begin])  
              return assistFindMin(num, begin + 1, mid);  
            else {  
                if(num[mid] > num[end])  
                  return assistFindMin(num, mid + 1, end);  
                else   
                  return min(assistFindMin(num, begin, mid), assistFindMin(num, mid + 1, end));  
            }  
        }  
  
        int min(int a, int b) {  
            return a <= b ? a : b;  
        }  
};
