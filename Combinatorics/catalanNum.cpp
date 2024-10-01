#include <iostream>

using namespace std;

const int MOD = 1e6;
const int imx = 200;

int main() {
	int catalan[imx][imx];
	for (int i = 1; i < imx; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				catalan[i][j] = 1;
			} else {
				catalan[i][j] = (catalan[i][j - 1] + catalan[i - 1][j]) % MOD;
			}
		}
	}

	//OR Catalan of n = (ncr(2n, n)/(n+1));
	//OR Catalan of n = fact[2*n]*inv[n+1]*inv[n];
	//OR Catalan of n = ((2*(2*n-1)*Cat(n-1))/(n+1))

	int n;
	while (cin >> n) {
		if (n == 0) { break; }
		cout << catalan[n][n] << '\n';
	}
}
