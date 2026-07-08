class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Adjacency list: u -> (v, weight)
    vector<vector<pair<int,int>>> adj(n + 1);
    for (auto &t : times) {
        adj[t[0]].push_back({t[1], t[2]});
    }

    // Distance array
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [time, u] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (time > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > time + w) {
                dist[v] = time + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }

    return ans;
}
};