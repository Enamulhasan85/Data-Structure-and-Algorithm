#include <iostream>
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1e9+7;
const ll mxN = 2e5;
const ll imx = 200;

int main() {

	// Stirling 1st: From n different things divide into k cycles
	//     [n, k] = [n-1, k-1] + (n-1) * [n-1, k]
 	//     if k = 1 then [n, 1] = fact[n-1];
 	//     if k = n then [n, n] = 1;

    ll fact[mxN+5];
    fact[0] = 1;
    for(ll i=1;i<=mxN;i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }

 	ll stnum[imx+5][imx+5];

 	for(ll i=1;i<imx;i++){
        for(ll j=1;j<=i;j++){
            if(j==1) stnum[i][j] = fact[i-1];
            else if(j==i) stnum[i][j] = 1;
            else stnum[i][j] = (stnum[i-1][j-1] +
                        ((i-1) * stnum[i-1][j])%mod)%mod;
            //cout << stnum[i][j] << " ";
        }
 	}

 	cout << stnum[3][2] << " " << stnum[4][2] << " ";

}
