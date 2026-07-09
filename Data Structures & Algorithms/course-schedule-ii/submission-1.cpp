class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& x) {
        vector<vector<int>>a(n);
        vector<int>d(n, 0);

        for(auto &e : x){
            a[e[1]].push_back(e[0]);
            d[e[0]]++;
        }

        queue<int>q;

        for(int i = 0; i<n; i++){
            if(d[i] == 0){
                q.push(i);
            }
        }

        vector<int>v;

        while(!q.empty()){
            int t = q.front();
            q.pop();
            v.push_back(t);
            for(auto &i : a[t]){
                d[i]--;
                if(d[i] == 0){
                    q.push(i);
                }
            }
        }
        return v.size() != n ? vector<int>{} : v;
    }
};
