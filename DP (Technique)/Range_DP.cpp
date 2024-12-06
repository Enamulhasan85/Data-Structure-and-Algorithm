#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N], f[N][N], dp[N];

ll DP(ll i, ll j){
    if(i>j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans = 0;
    for(ll k=i+1;k<=j;k+=2){
        if(str[i]!=str[k]) continue;
        ll a1 = DP(i+1, k-1);
        ll a2 = DP(k+1, j);
        if(a1==0 or a2==0) continue;
        ll len = (j-i+1)/2, len_l = (k-i+1)/2;
        ans += ((a1*a2)%MOD * ncr(len, len_l))%MOD;
        ans %= MOD;
    }

    return dp[i][j] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int j = l; j < r; j++) {
                if (f[l][j] && f[l][j] == f[j + 1][r])
                    f[l][r] = f[l][j] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1e7;
        for (int j = 0; j < i; j++)
            if (f[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
    }

    cout << dp[n] << endl;
}