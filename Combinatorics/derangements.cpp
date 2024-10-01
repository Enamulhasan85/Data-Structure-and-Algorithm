#include <bits/stdc++.h>

using namespace std;

ll mod = 1e9+7;

int main() {
	int n, m;
	cin >> n >> m;

	vector<ll> dp(n);
	dp[2] = 1, dp[1] = 0;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((i - 1) * (dp[i-1] + dp[i-2]))%mod;
	}
	cout << endl;
}