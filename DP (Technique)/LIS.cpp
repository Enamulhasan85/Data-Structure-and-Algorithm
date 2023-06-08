#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main(){

    ll i, n, j, k, ans;

    cin >> n;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;

    vector<ll> mem(n, -1), lis, next(n);

    for(i=n-1;i>-1;i--){
        ll tmp = 1, pos = i;
        for(j=i+1;j<n;j++){
            if(v[i]<v[j] and tmp<mem[j]+1) tmp = mem[j]+1, pos = j;
        }
        mem[i] = tmp;
        next[i] = pos;
    }

    ans = 0;
    for(i=0;i<n;i++) {
        if(ans<mem[i]){
            ans = mem[i];
            k = i;
        }
    }

    cout << ans << endl;
    cout << v[k] << " ";
    while(k!=next[k]){
        k = next[k];
        cout << v[k] << " ";
    }

}
