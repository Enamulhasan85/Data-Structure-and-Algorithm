#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1e9+7;

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, 0);
        lazy.resize(4*sz, 0);
    }

    ll n;
    vector<ll> tree;
    vector<ll> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i]==0) return;
        if(l!=r){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        tree[i] += lazy[i]*(r-l+1);
        lazy[i] = 0;
    }

    ll combine(ll l, ll r){
        return l+r;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            tree[i] = v[l];
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            lazy[i] = val;
            push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val);
        update(i*2+1, mid+1, r, b, e, val);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
    }
    void Update(ll i, ll j, ll val){
        update(1, 0, n-1, i, j, val);
    }

    ll query(ll i, ll l, ll r, ll b, ll e){
        push(i, l, r);
        if(b<=l and r<=e) {
            return tree[i];
        }
        if(e<l or r<b) return 0;
        ll mid = (l+r)/2;
        return combine(query(i*2, l, mid, b, e), query(i*2+1, mid+1, r, b, e));
    }
    ll Query(ll i, ll j){
        return query(1, 0, n-1, i, j);
    }
};

void solve(ll cs)
{
    ll n, m, i, a, b, c, d, j, k, ans=0, mn = 1e15, mx, cnt, q;

    string s, s1 = "";
    cin >> n >> k;

    vector<ll> v(n, 0);

    //for(auto &x : v) cin >> x;

    segtree st = segtree(n);

    st.Build(v);

    cout << "Case " << cs << ": " << endl;

    while(k--){
        cin >> i;
        if(i==0){
            cin >> a >> b >> q;
            st.Update(a, b, q);
        }
        else{
            cin >> a >> b;
            cout << st.Query(a, b) << endl;
        }
    }
    //cout << ans;
    //cout << "No";

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t=1, cs=0;
    cin >> t;
    while(t--){
        solve(++cs);
    }
    return 0;
}



