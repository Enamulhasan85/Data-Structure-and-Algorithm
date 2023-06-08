#include<bits/stdc++.h>

using ll = long long;
using namespace std;

vector<ll> pv, wv;
ll mem[1000][1000];

ll dpop(ll i, ll n, ll w){
    if(i==n) return 0;
    if(w==0) return 0;
    if(mem[i][w]!=0) return mem[i][w];

    ll r1=0, r2=0;
    if(w-wv[i]>=0) r1 = pv[i] + dpop(i+1, n, w-wv[i]);
    r2 = dpop(i+1, n, w);

    return mem[i][w] = max(r1, r2);
}

int main(){

    ll i, num_of_int, j, k, weight, ans;

    cin >> num_of_int >> weight;
    pv = vector<ll>(num_of_int);
    wv = vector<ll>(num_of_int);
    for(auto &x : pv) cin >> x;
    for(auto &x : wv) cin >> x;

    ans = dpop(0, num_of_int, weight);
    cout << ans << endl;

}
