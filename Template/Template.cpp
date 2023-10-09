#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

void solve(ll cs){
    ll a=0, x, y, k, b=0, j, i, c, q, n, m, d, mn = 0, mx;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    //next_permutation(s.begin(), s.end()
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("watering_well_chapter_2_validation_input.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output.txt", "w", stdout);


    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}

