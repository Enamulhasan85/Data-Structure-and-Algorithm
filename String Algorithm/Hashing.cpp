#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define tup tuple<ll, ll, ll>

using ll = long long;
using namespace std;

const ll MOD = 1e9+7;

struct hash_st{
    string s;
    ll mod, base;
    vector<ll> h, hrev, pow;
    hash_st(string s, ll mod, ll base){
        this->mod=mod;
        this->s=s;
        this->base=base;
    }
    void init(){
        h.push_back(0);
        pow.push_back(1);
        for(ll i=0;i<s.size();i++){
            pow.push_back((pow.back() * base) % mod);
            ll tmp = ((h.back()*base)%mod+(s[i]-'0'+1))%mod;
            h.push_back(tmp);
        }
    }
    void init_reverse(){
        string srev=s;
        reverse(srev.begin(),srev.end());
        hrev.push_back(0);
        for(ll i=0;i<srev.size();i++){
            ll tmp=(hrev.back()*base+(srev[i]-'0'+1))%mod;
            hrev.push_back(tmp);
        }
    }
    ll get_hash(ll l, ll r){
        if(l<=r){
            return (h[r]-(h[l-1]*pow[r-l+1])%mod+mod)%mod;
        }
        else {
            l=s.size()-l+1;
            r=s.size()-r+1;
            return (hrev[r]-(hrev[l-1]*pow[r-l+1])%mod+mod)%mod;
        }
    }
};

void solve(ll cs)
{
    ll n, q, a, b;

    string s;
    cin >> s ;
    n = s.size();

    hash_st h1 = hash_st(s, MOD, 71);
    h1.init();
    h1.init_reverse();


    hash_st h2 = hash_st(s, MOD, 73);
    h2.init();
    h2.init_reverse();


    ll hs = h1.get_hash(1, n), hsr = h1.get_hash(n, 1);
    ll hss = h2.get_hash(1, n), hssr = h2.get_hash(n, 1);

    cout << hs << endl;
    cout << hsr << endl;
    cout << hss << endl;
    cout << hssr << endl;

    cin >> q;
    while(q--){
        cin >> a >> b;

        cout << h1.get_hash(a, b) << " ";
        cout << h2.get_hash(a, b) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll t=1, cs=1;
    //cin >> t;
    while(t--)
    {
        //string str;
        //getline(cin, str);
        solve(cs++);
        //cout << endl;
    }
}
