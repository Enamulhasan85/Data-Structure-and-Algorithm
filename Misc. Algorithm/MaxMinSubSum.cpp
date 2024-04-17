#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 998244353;

void solve(ll cs){
    ll j, i, p, q, a, b, c, d, m, n, k, mn = 0, mx = 998244353;

    string s, s1, s2;

    cin >> n;

    vector<ll> v(n), pre(n);
    for(auto &x : v) cin >> x;

	// at least length 2
    mn = 0, mx = 0;
    ll sum = 0;
    for(i=0;i<n;i++){
        sum += v[i];
        pre[i] = sum;
        if(-1<i-2) mx = max(mx, pre[i-2]);
        if(i>0) mn = min(mn, sum-mx);
    }

    p = 0;
    for(auto x : v) p += x;

    p -= mn;
    cout << p+abs(mn) ;
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("output3.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output6.txt", "w", stdout);


    ll t=1, cs=1;
    cin >> t;
    while(t--){
        //string str;
        //getline(cin, str);
        solve(cs++);
    }
}
