#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct node{
    ll val, prop;
};

vector<node> seg(1000001);
vector<ll> arr;

void init(ll node, ll l, ll r){
    if(l==r){
        seg[node].val = arr[l];
        seg[node].prop = 0;
        return;
    }
    ll mid = (l+r)/2;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    seg[node].val = seg[2*node].val + seg[2*node+1].val;
    seg[node].prop = 0;
}

ll query(ll node, ll l, ll r, ll i, ll j, ll carry = 0){
    if(r<i or l>j) return 0;
    if(i<=l and r<=j) return seg[node].val + carry*(r-l+1);
    ll mid = (l+r)/2;
    ll x = query(2*node, l, mid, i, j, carry+seg[node].prop);
    ll y = query(2*node+1, mid+1, r, i, j, carry+seg[node].prop);
    return x+y;
}

void update(ll node, ll l, ll r, ll i, ll j, ll k){
    if(i<=l and r<=j){
        seg[node].prop = k;
        seg[node].val += (r-l+1)*k;
        return;
    }
    if(j<l or i>r) return;
    ll mid = (l+r)/2;
    update(2*node, l, mid, i, j, k);
    update(2*node+1, mid+1, r, i, j, k);
    seg[node].val = seg[2*node].val + seg[2*node+1].val + (r-l+1)*seg[node].prop;
}

int main(){
    ll i, n, j, k;
    cin >> n;
    arr = vector<ll>(n);

    for(auto &x : arr) cin >> x;

    init(1, 0, n-1);

    k = query(1, 0, n-1, 0, 6);
    cout << k << endl;

    update(1, 0, n-1, 4, 4, 10);

    k = query(1, 0, n-1, 0, 6);
    cout << k << endl;
}
