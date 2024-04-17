#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1000000007;

pair<string, ll> dp[19][2][2][2];

pair<string, ll> DP(ll i, ll l, ll h, ll st, string &s1, string &s2){
    if(i==s1.size()) return {"", 1};
    if(dp[i][l][h][st].se!=-1) return dp[i][l][h][st];

    ll s = s1[i]-'0', e = s2[i]-'0';
    if(l) s = 0;
    if(h) e = 9;

    pair<string, ll> ans = {"", -1};
    for(ll j=s;j<=e;j++){
        ll is_l = l;
        if(j>s1[i]-'0') is_l = 1;

        ll is_h = h;
        if(j<s2[i]-'0') is_h = 1;

        ll is_st = st;
        if(j!=0) is_st = 1;

        pair<string, ll> pi = DP(i+1, is_l, is_h, is_st, s1, s2);
        char ch = '0'+j;
        pi.fi = ch + pi.fi;
        if(is_st) pi.se = pi.se * j;

        //cout << pi.fi << " " << pi.se << endl;
        if(ans.se<pi.se) ans = pi;
        //ans %= mod;
    }

    return dp[i][l][h][st] = ans;
}




void solve(ll cs)
{
    ll n, m, i, a, b, c, d, j, k, ans=0, mn = 1e15, mx, cnt, q;

    string s, s1, s2;

    cin >> a >> b;

    //vector<ll> v(n);

    s1 = to_string(a);
    s2 = to_string(b);

    s = "";
    for(i=s1.size();i<19;i++) s += '0';
    s1 = s + s1;

    s = "";
    for(i=s2.size();i<19;i++) s += '0';
    s2 = s + s2;

    for(auto &x : dp) for(auto &xx : x) for(auto &xxx : xx) for(auto &xxxx : xxx) xxxx = {"", -1};

    pair<string, ll> pi = DP(0, 0, 0, 0, s1, s2);

    bool ok = 1;
    for(i=0;i<pi.fi.size();i++){
        if(pi.fi[i]=='0' and ok) continue;
        else ok = 0;
        cout << pi.fi[i];
    }

    cout << endl;

}


ll dp[51][17][17][17][2];

ll DP(ll i, ll c1, ll c2, ll c3, ll u, string &s){
    //cout << sz << " ";
    ll mx = max(c1, max(c2, c3));
    mx = 3*mx - (c1+c2+c3);
    if(51-i<mx) return 0;
    if(i==s.size()) {
        if(c1==c2 and c2==c3 and c1>=1) return 1;
        else return 0;
    }
	//Optimization technique
    if(dp[i][c1][c2][c3][u]!=-1 and u) return dp[i][c1][c2][c3][u];

    ll ans = 0;

    for(ll j=0;j<=9;j++){
        ll num = (s[i]-'0');
        if(!u and j>num) break;

        ll is_u = u;
        if(j<num) is_u = 1;
/*
        ll is_st = st;
        if(j!=0) is_st = 1;
*/
        ll nc1 = c1 + ((j==3) ? 1 : 0);
        ll nc2 = c2 + ((j==6) ? 1 : 0);
        ll nc3 = c3 + ((j==9) ? 1 : 0);
        ans += DP(i+1, nc1, nc2, nc3, is_u, s);
        ans %= mod;
        //cout << ans << " " << i << " " << pos << " " << j << endl;
    }

    return dp[i][c1][c2][c3][u] = ans;
}

void solve(ll cs)
{
    ll n, m, i, a, b, c, d, j, k, ans=0, mn = 1e15, mx, cnt, q;
    string s, s1, s2;
    cin >> s1 >> s2;

    mn = 51 - s1.size(), s = "";
    while(mn--) s += '0';
    s1 = s + s1;

    mn = 51 - s2.size(), s = "";
    while(mn--) s += '0';
    s2 = s + s2;

    ans = DP(0, 0, 0, 0, 0, s2);
    ans -= DP(0, 0, 0, 0, 0, s1);

    ll c1 = 0, c2 = 0, c3 = 0;
    for(auto x : s1) {
        c1 += ((x=='3') ? 1 : 0);
        c2 += ((x=='6') ? 1 : 0);
        c3 += ((x=='9') ? 1 : 0);
    }

    if(c1==c2 and c2==c3 and c1>0) ans++;
    if(ans<0) ans += mod;

    cout << ans;
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t=1, cs=0;
    //cin >> t;
    while(t--){
        solve(++cs);
    }
    return 0;
}

