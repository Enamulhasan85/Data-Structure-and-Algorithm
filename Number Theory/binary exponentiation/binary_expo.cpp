#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1000000007;

ll binpow(ll a, ll b, ll mod){
    ll res = 1, i;
    for(i=0;(1ll<<i)<=b;i++){
        if(b&(1ll<<i)) res *= a, res %= mod;
        a *= a;
		a %= mod;
    }
    return res;
}

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, mx = 1e10;

    string s, s1;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << binpow(a, b, mod) << endl;
    }

    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}
