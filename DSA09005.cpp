#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int V, E, u;
vector<int> adj[1001];
bool visited[1001];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        cout << x << " ";
        for (int v : adj[x]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E >> u;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x); 
        }
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        memset(visited, false, sizeof(visited));
        bfs(u);
    }
}
