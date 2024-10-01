#include<bits/stdc++.h>
#define tup tuple<ll, ll>
#define pi pair<ll, ll>
#define endl '\n'

using namespace std;
using ll = long long;

const ll imx = 2e5+5;
ll mod = 1e9+7;

vector<pi> g[imx];
vector<ll> dis, v1;

void dijkstra(ll i){
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    dis[i] = 0;
    pq.push({dis[i], i});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        //cout << d << " " << u << endl;
        if(d != dis[u]) continue;
        for(auto x : g[u]){
            if(dis[u] + x.second < dis[x.first]){
                dis[x.first] = dis[u] + x.second;
                pq.push({dis[x.first], x.first});
            }
        }
    }
}

int main(){

    ll n, m, i, j;

    cin >> n >> m;

    dis = vector<ll> (n+1, 1e18);
    for(i=0;i<m;i++){
        ll u, v, cost;
        cin >> u >> v >> cost;
        g[u].push_back({v, cost});
        g[v].push_back({u, cost});
    }

    dijkstra(1);
    for(auto x : dis) cout << x << " ";

}
