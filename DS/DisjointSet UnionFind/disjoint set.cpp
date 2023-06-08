/* DISJOIN SET UNION FIND*/

#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<ll> par;

ll fd(ll r){
    if(r==par[r]) return r;
    par[r] = fd(par[r]);
    return par[r];
}

void uni(ll a, ll b){
    ll u = fd(a);
    ll v = fd(b);
    if(u==v){
        cout << "They are already friends" << endl;
    }
    else{
        par[u] = v;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, i, x;
    cin >> n;
    for(i=0;i<n+1;i++) {
        par.push_back(i);
    }
    uni(1,2);
    uni(2,3);
    uni(4,5);
    uni(5,3);
    cout << fd(1) << endl;
}
