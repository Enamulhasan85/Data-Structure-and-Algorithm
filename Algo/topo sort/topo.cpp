#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> v[1000000];

void toposort(ll i, vector<bool> &vis, stack<ll> &st){
    vis[i] = true;

    for(auto x : v[i]){
        if(!vis[x]) toposort(x, vis, st);
    }

    st.push(i);
}

void solve(ll cs){
    ll i, n, j, m, a, b;

    cin >> n >> m;
    vector<bool> vis(n, false);

    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
    }

    stack<ll> st;

    for(i=0;i<n;i++) {
        if(!vis[i]) toposort(i, vis, st);
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}

int main(){

    ll cs = 0, t = 1;
    //cin >> t;

    while(t--){
        solve(++cs);
    }
}
