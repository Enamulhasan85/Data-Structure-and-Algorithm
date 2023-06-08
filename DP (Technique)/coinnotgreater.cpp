#include<bits/stdc++.h>

using ll = long long;
using namespace std;

vector<ll> v;
ll mem[1000][1000];

ll dpop(ll i, ll n, ll w, ll k){
    if(w<0) return 1e9;
    if(i==n and w!=0) return 1e9;
    if(w==0) return 0;
    if(mem[i][w]!=0) return mem[i][w];

    ll ans = 1e9;
    for(ll j=0;j<=k;j++){
        ans = min(ans, j+dpop(i+1, n, w-j*v[i], k));
    }

    return mem[i][w] = ans;
}

int main(){

    ll i, n, j, k, w, ans;

    cin >> n >> w >> k;
    v = vector<ll>(n);
    for(auto &x : v) cin >> x;

    ans = dpop(0, n, w, k);
    cout << ans << endl;

}
