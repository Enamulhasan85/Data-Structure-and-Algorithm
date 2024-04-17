#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1000000007;

void mat_mul(vector<vector<ll>>&mat1, vector<vector<ll>> &mat2){
    vector<vector<ll>> newmat(2, vector<ll>(2, 0));
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
            for(ll k=0;k<2;k++) newmat[i][j] += mat1[i][k]*mat2[k][j];
        
    mat1 = newmat;
}

ll fib(ll n){
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 1;
    vector<vector<ll>> resmat, mat;
    resmat = mat = {{0, 1}, {1, 1}};
    ll i;
    n-=3;
    for(i=0;(1ll<<i)<=n;i++){
        if(n&(1ll<<i)) mat_mul(resmat, mat);
        mat_mul(mat, mat);
        //cout << mat[0][0] << mat[0][1] << mat[1][0] << mat[1][1];
    }
    return resmat[1][1];
}

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, mx = 1e10;

    string s, s1;
    cin >> n;
    
    cout << fib(n) << " ";

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t=1, cs=1;
    cin >> t;
    while(t--){
        solve(cs++);
    }
}
