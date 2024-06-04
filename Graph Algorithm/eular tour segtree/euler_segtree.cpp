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

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, 0);
    }
    ll n;
    vector<ll> tree;

    ll combine(ll l, ll r){
        if(l==-1) return r;
        if(r==-1) return l;
        if(tin[l]<tin[r]) return l;
        else return r;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r){
            tree[i] = v[l];
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
    }

    ll query(ll i, ll l, ll r, ll b, ll e){
        if(e<l or r<b) return -1;
        if(b<=l and r<=e){
            return tree[i];
        }
        ll mid = (l+r)/2;
        return combine(query(i*2, l, mid, b, e), query(i*2+1, mid+1, r, b, e));
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

    segtree st = segtree(et.size());
    st.build(1, 0, et.size()-1, et);

    while(k--){
        cin >> a >> b;
        if(tin[a]>tin[b]) swap(a, b);
        mn = st.query(1, 0, et.size()-1, tin[a], tin[b]);
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
