#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int V, E, u;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
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
        dfs(u);
        cout << endl;
    }
    return 0;
}
