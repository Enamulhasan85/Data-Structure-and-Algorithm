#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e4;

int timer;
vector<int> low, id;
vector<bool> visited, ap;
vector<vector<int>> g(NMAX);

void dfs(int node, int parent) {
	visited[node] = true;
	id[node] = low[node] = timer++;

	int children = 0;
	for (int son : g[node]) {
		if (son == parent) { continue; }

		if (!visited[son]) {
			dfs(son, node);
			low[node] = min(low[node], low[son]);
			children++;

			// Check if the current node is an articualation point
			if (low[son] >= id[node] && parent != -1) { ap[node] = true; }
		} else {
			low[node] = min(low[node], id[son]);
		}
	}

	if (parent == -1 && children > 1) { ap[node] = true; }
}

int main() {
	int n, m;
	while (cin >> n >> m && n && m) {
		id.assign(n, 0);
		ap.assign(n, 0);
		low.assign(n, 0);
		visited.assign(n, 0);
		for (int i = 0; i < n; i++) { g[i].clear(); }

		timer = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			g[--x].push_back(--y);
			g[y].push_back(x);
		}

		dfs(0, -1);

		int articualation_points = 0;
		for (int i = 0; i < n; i++) {
			if (ap[i]) { articualation_points++; }
		}
		cout << articualation_points << '\n';
	}
}