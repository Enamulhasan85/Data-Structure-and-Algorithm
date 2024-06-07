#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;
bool vis[MAX];
int lca[MAX], fa[MAX];
vector<array<int, 2>> adj[MAX], qry[MAX];
int find(int u) { return (fa[u] == u) ? u : fa[u] = find(fa[u]); }
void tarjan(int node) {
	vis[node] = true;
	for (auto [nxt, id] : adj[node]) {
		if (vis[nxt]) { continue; }
		tarjan(nxt);
		fa[nxt] = node;
	}
	for (auto &[nxt, id] : qry[node]) {
		if (vis[nxt]) { lca[id] = find(nxt); }
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	iota(fa, fa + n + 1, 0);
	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		adj[i].push_back({a, i});
		adj[a].push_back({i, i});
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		qry[a].push_back({b, i});
		qry[b].push_back({a, i});
	}
	tarjan(1);
	for (int i = 0; i < m; i++) { cout << lca[i] << "\n"; }
}
