#include<bits/stdc++.h>
using ll = long long;
using namespace std;

vector<ll> v;
ll mem[1000][1000];

ll dp(ll i, ll n, ll k){
    if(i==n and k!=0) return 1e9;
    if(k==0) return 0;
    if(mem[i][k]!=0) return mem[i][k];

    ll r1 = 1e9, r2 = 1e9;
    if(k-v[i]>=0) r1 = 1+dp(i+1, n, k-v[i]);
    r2 = dp(i+1, n, k);

    return mem[i][k] = min(r1, r2);

}

int main(){

    ll i, n, j, k, ans;

    cin >> n >> k;
    v = vector<ll>(n);
    for(auto &x : v) cin >> x;

    ans = dp(0, n, k);
    cout << ans << endl;
}
