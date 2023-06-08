#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

vector<vector<pair<ll, ll>>> v;
map<ll, ll> dis;

ll dijkstra(ll i){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[i] = 0;
    pair<ll, ll> pi;
    pq.push({0, i});
    while(!pq.empty()){
        pi = pq.top();
        pq.pop();
        ll u = pi.second;
        for(auto x : v[u]){
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
    v = vector<vector<pair<ll, ll>>> (n+1, vector<pair<ll, ll>>(0));

    for(i=1;i<=n;i++) dis[i] = 1e12;
    for(i=0;i<m;i++){
        ll u, vv, cost;
        cin >> u >> vv >> cost;
        v[u].push_back({vv, cost});
        v[vv].push_back({u, cost});
    }

    ll ans = dijkstra(1);

    for(auto x : dis) cout << x.second << " ";

}
