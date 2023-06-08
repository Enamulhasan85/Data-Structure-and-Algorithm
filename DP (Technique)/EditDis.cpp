#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<ll>> mem(1000, vector<ll> (1000, -1));

int dp(int i, int j, string s1, string s2){
    if(i==n) return m-j;
    if(j==m) return n-i;

    if(mem[i][j]!=-1) return mem[i][j];

    int ans = 0;
    if(s1[i]==s2[j]) ans = dp(i+1, j+1, s1, s2);
    else{
        ans = 1 + min(dp(i+1, j, s1, s2), min(dp(i, j+1, s1, s2), dp(i+1, j+1, s1, s2)));
    }
    return mem[i][j] = ans;
}

int main(){
    ll i, j;

    string s1, s2;
    cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();

    int ans = dp(0, 0, s1, s2);

    cout << ans << endl;

}
