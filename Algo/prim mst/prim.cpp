#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1e9+7;
vector<pair<ll, ll>> v[1000006];

double primmst(ll i, ll n){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    vector<ll> key(n+1, 1e9);
    vector<ll> par(n+1, -1);
    vector<bool> inmst(n+1, false);

    ll src = 1, tot = 0;
    key[src] = 0;
    pq.push({key[src], src});

    while(!pq.empty()){
        pair<ll, ll> pi = pq.top();
        pq.pop();

        if(inmst[pi.se]) continue;
        inmst[pi.se] = true;
        tot += pi.fi;

        for(auto x : v[pi.se]){
            if(!inmst[x.fi] and key[x.fi]>x.se){
                key[x.fi] = x.se;
                pq.push({key[x.fi], x.fi});
                par[x.fi] = pi.se;
            }
        }
    }

    for(i=2;i<n+1;i++) cout << par[i] << " " << i << endl;

    return tot;

}

void solve(ll cs){
    ll n, m=0, j, q, k=0, i=0, t, x=0, y, a, b, d, c;

    cin >> n >> m;

    while(m--){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    ll ans = primmst(1, n);
    cout << ans << endl;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t = 1, cs = 0;
    cin >> t;
    while(t--){
        if(cs!=0) cout << endl;
        solve(++cs);
    }
}
