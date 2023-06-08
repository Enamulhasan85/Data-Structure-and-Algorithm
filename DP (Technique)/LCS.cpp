#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll i, j, n, m;

    string s1, s2;
    cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();

    vector<vector<ll>> mem(n+1, vector<ll> (m+1, 0));

    for(i=n-1;i>-1;i--){
        for(j=m-1;j>-1;j--){
            if(s1[i]==s2[j]){
                mem[i][j] = 1 + mem[i+1][j+1];
            }
            else{
                mem[i][j] = max(mem[i+1][j], mem[i][j+1]);
            }
        }
    }

    cout << mem[0][0] << endl;

}
