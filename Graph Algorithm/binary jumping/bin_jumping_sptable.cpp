#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5;
const int LOG = 19;
int up[LOG][MAX], depth[MAX];
vector<int> adj[MAX];
void dfs(int node, int prev, int dist) {
	depth[node] = dist;
	if (prev != -1) { up[0][node] = prev; }
	for (int i = 1; i < LOG; i++) { up[i][node] = up[i - 1][up[i - 1][node]]; }
	for (int nxt : adj[node]) {
		if (nxt != prev) { dfs(nxt, node, dist + 1); }
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) { swap(a, b); }
	int dist = depth[a] - depth[b];
	for (int i = LOG - 1; i >= 0; i--) {
		if ((dist >> i) & 1) { a = up[i][a]; }
	}
	if (a == b) { return a; }
	for (int i = LOG - 1; i >= 0; i--) {
		if (up[i][a] != up[i][b]) {
			a = up[i][a];
			b = up[i][b];
		}
	}
	return up[0][a];
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int b;
		cin >> b;
		adj[--b].push_back(i);
	}
	dfs(0, -1, 0);
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cout << lca(--x, --y) + 1 << "\n";
	}
}
