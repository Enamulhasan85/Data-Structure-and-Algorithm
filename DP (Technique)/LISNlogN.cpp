#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main(){

    ll i, n, j, k, ans;

    cin >> n;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;

    vector<ll> mem;

    for(auto x : v){
        ll ind = lower_bound(mem.begin(), mem.end(), x) - mem.begin();

        if(ind==mem.size()) mem.push_back(x);
        else mem[ind] = x;
        for(auto xx : mem) cout << xx << " ";
        cout << endl;
    }

    cout << mem.size();

}
