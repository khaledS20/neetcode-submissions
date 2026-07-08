class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<int>minDist(n, INT_MAX);
        vector<bool>visited(n, false);
        int result = 0;

        minDist[0] = 0;

        for(int i =0; i<n; i++){
            int unVisitedNode = -1;

            for(int j = 0; j<n ; j++){
                if(!visited[j]&&(unVisitedNode == -1 || minDist[j]<minDist[unVisitedNode])){
                    unVisitedNode = j;
                }
            }

            visited[unVisitedNode] = true;
            result+=minDist[unVisitedNode];

            for(int v = 0; v<n; v++){
                int cost =abs(points[unVisitedNode][0] - points[v][0])+
                          abs(points[unVisitedNode][1] - points[v][1]);
                minDist[v] = min(minDist[v], cost);
            }
        }

        return result;
    }
};
