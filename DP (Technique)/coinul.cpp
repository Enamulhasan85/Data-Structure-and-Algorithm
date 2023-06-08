#include<bits/stdc++.h>

using ll = long long;
using namespace std;

vector<ll> v;
ll mem[10000];

ll dpop(ll n, ll k){
    if(k<0) return 1e9;
    if(k==0) return 0;
    if(mem[k]!=0) return mem[k];

    ll ans = 1e9;
    for(ll i=0;i<n;i++){
        ans = min(ans, 1+dpop(n, k-v[i]));
    }

    return mem[k] = ans;

}

int main(){

    ll i, n, j, k, ans;

    cin >> n >> k;
    v = vector<ll>(n);
    for(auto &x : v) cin >> x;

    ans = dpop(n, k);
    cout << ans << endl;

}
