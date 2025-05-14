#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;
vector<int> adj[1001];
bool visited[1001];
bool dfs(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}
bool hasCycle() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) return true;
        }
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        for (int i = 0; i <= V; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        cout << (hasCycle() ? "YES" : "NO");
    }
}
