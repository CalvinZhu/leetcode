//http://cozilla.iteye.com/blog/1952500
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = gas[i] - cost[i];
        int s = 0, e = 0, t = 0;
        while (s < n) {
            while (t >= 0 && e < s + n) t += v[(e++) % n];
            if (t >= 0 && e == s + n) return s;
            t -= v[s];
            s++;
        }
        return -1;
    }
};
