#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1e9+7;
vector<ll> v[1000006];

void dfs(ll i, vector<ll> &col, vector<ll> &d, vector<ll> &f, vector<ll> &par, ll &time){
    col[i] = 1;
    d[i] = ++time;
    for(auto x : v[i]){
        if(col[x]==0) {
            par[x] = i;
            dfs(x, col, d, f, par, time);
        }
    }

    col[i] = 2;
    f[i] = ++time;
}

void solve(ll cs){

    ll n, m, i, j;
    cin >> n >> m;

    while(m--){
        cin >> i >> j;
        v[i].push_back(j);
    }

    ll time = 0;
    vector<ll> col(n+1, 0), d(n+1), f(n+1), par(n+1, NULL);
    for(i=1;i<=n;i++) if(col[i]==0) dfs(i, col, d, f, par, time);

    vector<pair<ll, ll>> vs;
    for(i=1;i<=n;i++) vs.push_back({f[i], i});
    sort(vs.rbegin(), vs.rend());

    time = 0;
    col = vector<ll> (n+1, 0);
    for(auto x : vs){
        if(col[x.se]==0) dfs(x.se, col, d, f, par, time);
    }

    for(i=1;i<=n;i++) cout << d[i] << " " << f[i] << " " << par[i] << endl;

}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t = 1, cs = 0;
    //cin >> t;
    while(t--){
        solve(++cs);
    }
}
