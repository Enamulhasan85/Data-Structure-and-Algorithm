#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Chinese Remainder Theorem O(n*log(max_modVal))
const int N = 20;
ll GCD(ll a, ll b)
{
    return (b==0)?a:GCD(b, a%b);
}
ll LCM(ll a, ll b)
{
    return a/GCD(a, b)*b;
}
ll normalize(ll x, ll mod)
{
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
struct GCD_type
{
    ll x, y, d;
};
GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x-a/b*pom.y, pom.d};
}
ll rem[N], modVal[N], ans, lcm;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin>>rem[i]>>modVal[i];
    ans = rem[1];
    lcm = modVal[1];
    for(int i = 2; i <= n; i++)
    {
        auto pom = ex_GCD(lcm, modVal[i]);
        int x1 = pom.x, d = pom.d;
        if((rem[i] - ans) % d != 0)
            return cerr<<"No solutions"<<endl, 0;
        ans=normalize(ans+x1*(rem[i]-ans)/d%
                      (modVal[i]/d)*lcm, lcm*modVal[i]/d);
        lcm = LCM(lcm, modVal[i]);
    }
    cout << ans << " " << lcm << endl;
}
