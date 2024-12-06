#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; 
vector<int> adj[MAXN];   
vector<pair<int, int>> bridges;
int tin[MAXN], low[MAXN], timer; 
bool visited[MAXN]; 

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++; 
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }
        }
    }
}

void findBridges(int n) {
    timer = 0;
    bridges.clear();
    memset(visited, false, sizeof(visited));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findBridges(n);

    cout << "Articulation Bridges:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}
