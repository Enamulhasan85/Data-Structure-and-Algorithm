ll mod = 1e9+7;
const ll mxN = 2e5;

ll fact[mxN+5], inv[mxN + 5];

ll binpow(ll a, ll b, ll mod)
{
    a %= mod;
    ll res = 1LL;
    while (b > 0)
    {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void pre()
{
    ll i, ans = 1;
    fact[0] = 1;
    for(i=1;i<=mxN;i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    inv[mxN] = binpow(fact[mxN], mod - 2, mod);
    for(i=mxN-1;i>=0;i--)
    {
        inv[i] = inv[i+1] * (i+1);
        inv[i] %= mod;
    }
}

ll ncr(ll n, ll r){
    if(r==0) return 1;
    if(n<r) return 0;
    return (fact[n]*((inv[r]*inv[n-r])%mod))%mod;
}