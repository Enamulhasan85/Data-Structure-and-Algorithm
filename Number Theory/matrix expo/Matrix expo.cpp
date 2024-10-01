ll mod = 1e9+7;

void mat_mul(vector<vector<ll>> &m1, vector<vector<ll>> &m2, ll mod){

    ll n = m1.size(), i, j, k;

    vector<vector<ll>> mat(n, vector<ll> (n));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll tmp = 0;
            for(k=0;k<n;k++){
                tmp += (m1[i][k]*m2[k][j])%mod;
                tmp %= mod;
            }
            mat[i][j] = tmp;
        }
    }

    m1 = mat;
}

vector<vector<ll>> binmatpow(vector<vector<ll>> a,
                             ll b, ll mod){

    ll i, n = a.size();

    vector<vector<ll>> res(n, vector<ll> (n, 0));
    for(i=0;i<n;i++) res[i][i] = 1;

    for(i=0;(1LL<<i)<=b;i++){
        if(b&(1LL<<i)) mat_mul(res, a, mod);
        mat_mul(a, a, mod);
    }
    return res;
}