
const ll MXN = 1e6;
ll a[MXN+5], mul[MXN + 5], f[MXN + 5], g[MXN + 5], mp[MXN + 5];

void solve()
{
    ll n=0, q=0, i=0, j=0, k=0, m=0, x=0, ans=0;
    cn n;
    fori
    {
        cn a[i];
        m = max(m, a[i]);
        mp[a[i]]++;
    }
    for(i=1; i<=MXN; i++)
    {
        mul[i] = mp[i];
        for(j=i+i; j<=MXN; j+=i) mul[i] += mp[j];
    }

    // Exclusion DP

    // f[i] = number of pairs with gcd = multiple of i
    // g[i] = number of pairs with gcd = i
    for(i=1;i<=m;i++)
    {
        x = mul[i];
        f[i] = (x * (x-1))/2LL;
    }
    for(i=m;i>0;i--)
    {
        g[i] = f[i];
        for(j=i+i;j<=m;j+=i)
        {
            g[i] -= g[j];
        }
    }
    cout<<g[1];
}
