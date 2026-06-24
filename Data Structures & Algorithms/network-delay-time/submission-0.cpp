class Solution {
public:
    typedef pair<int, int> P;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int tm = times[i][2];

            adj[u].push_back({v, tm});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n + 1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {

            int curTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip stale entries
            if (curTime > dist[u]) continue;

            for (auto &it : adj[u]) {

                int v = it.first;
                int tm = it.second;

                if (curTime + tm < dist[v]) {

                    dist[v] = curTime + tm;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};