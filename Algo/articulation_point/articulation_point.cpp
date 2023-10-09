#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

vector<ll> parent, v[200006], dis, low;
vector<bool> vis, arti_point;
ll t = 0, ans = 0, root = 1;

void dfs(ll i){
    vis[i] = true;
    low[i] = dis[i] = t++;
    for(auto x : v[i]){
        if(vis[x]==false){
            parent[x] = i;
            dfs(x);
            if(root==i){
                if(!arti_point[i] and dis[i]<low[x] and v[i].size()>1){
                    arti_point[i] = true;
                }
            }
            else if(dis[i]<=low[x]){
                arti_point[i] = true;
            }
            else low[i] = min(low[i], low[x]);
        }
        else if(parent[i]!=x){
            low[i] = min(low[i], dis[x]);
        }
    }
}

void solve(ll cs){
    ll n, m, a=0, x, y, k, b=0, j, i, c, q, mn = 1e12, mx, mod = 998244353;

    cin >> n >> m;

    for(i=0;i<=n;i++) v[i].clear();
    vis = vector<bool> (n+1, 0);
    parent = vector<ll> (n+1, 0);
    dis = vector<ll> (n+1, 0);
    low = vector<ll> (n+1, 0);
    arti_point = vector<bool> (n+1, false);

    while(m--){
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    ans = 0;

    dfs(1);

    for(i=1;i<=n;i++) {
        cout << arti_point[i] << " ";
        if(arti_point[i]) ans++;
    }
    cout << ans << endl;

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}

