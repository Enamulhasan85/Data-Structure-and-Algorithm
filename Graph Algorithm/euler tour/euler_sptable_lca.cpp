#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

vector<ll> g[200006];
vector<ll> et, tin, tout;
ll t = 0;

void dfs(ll i, ll p){
    et.pb(i);
    tin[i] = t++;
    for(auto x : g[i]){
        if(x!=p){
            dfs(x, i);
            et.pb(i);
            tout[i] = t++;
        }
    }
}

struct sptable{
    sptable(ll sz){
        n = sz;
        log = log2(n)+1;
        st = vector<vector<ll>>(n, vector<ll> (log, 0));
    }
    ll n, log;
    vector<vector<ll>> st;

    ll combine(ll l, ll r){
        if(l==-1) return r;
        if(r==-1) return l;
        if(tin[l]<tin[r]) return l;
        else return r;
    }

    void build(vector<ll> &v){
        for(ll i=0;i<n;i++)
            st[i][0] = v[i];

        for(ll i=1;i<log;i++){
            for(ll j=0;j<n-(1<<i)+1;j++){
                st[j][i] = combine(st[j][i-1], st[j+(1<<(i-1))][i-1]);
            }
        }
    }

    ll query(ll a, ll b){
        ll i = b-a+1;
        i = log2(i);
        return combine(st[a][i], st[b-(1<<i)+1][i]);
    }
};

void solve(ll cs){
    ll a=0, x, y, k, b=0, j, i, c, q, n, m, d, mn = 0, mx;

    cin >> n >> k;
    for(i=0;i<n-1;i++) {
        cin >> b;
        g[i+2].pb(b);
        g[b].pb(i+2);
    }

    t = 0;
    tin.resize(n+1, 0);
    tout.resize(n+1, 0);
    dfs(1, -1);

    sptable st = sptable(et.size());
    st.build(et);

    while(k--){
        cin >> a >> b;
        if(tin[a]>tin[b]) swap(a, b);
        mn = st.query(tin[a], tin[b]);
        cout << mn << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("watering_well_chapter_2_validation_input.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output.txt", "w", stdout);


    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}
