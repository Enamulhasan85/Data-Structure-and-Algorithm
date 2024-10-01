#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// Returns length of function f
// or longest common substring
// of X[0..m-1] and Y[0..n-1]
int lcs(int i, int j, int count)
{

    if (i == 0 || j == 0)
        return count;

    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}

int main(){
    ll i, j, n, m;

    string s1, s2;
    cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();

    //subseq
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
