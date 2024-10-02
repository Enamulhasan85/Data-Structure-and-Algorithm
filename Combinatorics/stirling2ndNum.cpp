#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1e9+7;
const ll imx = 200;

int main() {

	// Stirling 2nd: From n different things divide into k
	// {n, k} = {n-1, k-1} + k * {n-1, k}
 	// if k = 1 then {n, 1} = 1;
 	// if k = n then {n, n} = 1;

 	ll stnum[imx+5][imx+5];

 	for(ll i=1;i<imx;i++){
        for(ll j=1;j<=i;j++){
            if(j==1 || j==i) stnum[i][j] = 1;
            else stnum[i][j] = (stnum[i-1][j-1] +
                        (j * stnum[i-1][j])%mod)%mod;
            //cout << stnum[i][j] << " ";
        }
 	}

 	cout << stnum[3][2] << " " << stnum[4][2] << " ";

}

