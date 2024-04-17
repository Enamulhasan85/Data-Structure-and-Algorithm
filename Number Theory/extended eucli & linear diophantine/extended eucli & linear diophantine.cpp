#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1000000007;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, mx = 1e10;

    cin >> n;
    while(n--){
        cin >> a >> b;
        ll x, y;
        ll g = gcd(abs(a), abs(b), x, y);
        if (a < 0) x = -x;
        if (b < 0) y = -y;
        cout << g << " " << x << " " << y;

        cout << " => ";

        // linear diophantine ax + by = c .. q = c/gcd(a,b)
        double c1;
        cin >> c1;
        double q = c1/g;
        cout << "a" << x*q << " b" << y*q << endl;
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
