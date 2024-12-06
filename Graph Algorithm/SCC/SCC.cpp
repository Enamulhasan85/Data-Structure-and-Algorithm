#include <bits/stdc++.h>

const ll mxn = 3e5 + 5;
vector<ll> adj[mxn], adj_t[mxn];
vector<ll> order;
vector<ll> vis(mxn), id(mxn);

void dfs1(ll v) {
	vis[v] = true;
	for (ll u : adj[v]) {
		if (!vis[u]) { dfs1(u); }
	}
	order.push_back(v);
}

void dfs2(ll x, ll comp) {
	vis[x] = true;

	for (ll u : adj_t[x]) {
		if (!vis[u]) { dfs2(u, comp); }
	}
	id[x] = comp;
}

int main() {
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		ll u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj_t[v].push_back(u);
	}

	vis.assign(N, false);
	for (ll i = 1; i <= n; i++) 
		if (!vis[i]) dfs1(i);

	vis.assign(N, false);
	reverse(order.begin(), order.end());
	ll comps = 0;
	for (ll v : order) {
		if (!vis[v]) {
			comps++;  // counter for SCC
			dfs2(v, comps);
		}
	}

	cout << comps << '\n';
	for (ll i = 1; i <= n; i++) { cout << id[i] << " \n"[i == n]; }
}