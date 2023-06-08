#include<bits/stdc++.h>
#define endl '\n'

using ll = long long;
using namespace std;

vector<ll> v[100005];
ll vis[100005], d[100005];

void bfs(ll x){
    ll n;
    queue<ll> q;
    for(ll i=0;i<100005;i++) vis[i] = 0;
    q.push(x);
    d[x] = 0;
    while(!q.empty()){
        x = q.front();
        vis[x] = 1;
        q.pop();
        for(auto xx : v[x]){
            if(vis[xx]==0){
                vis[xx] = 1;
                q.push(xx);
                d[xx] = d[x] + 1;
            }
        }
    }
}

void solve(ll cs){
    ll m, i, h, w, e, j, a=1, n, k=0, x, y, b, l=0, r=0, ans=2, mod=998244353;
    string s;
    cin >> n >> k;

    while(k--){
        cin >> x >> y;
        v[y].push_back(x);
        v[x].push_back(y);
    }

    bfs(1);
    for(i=0;i<10;i++) cout << d[i] << " ";

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}
