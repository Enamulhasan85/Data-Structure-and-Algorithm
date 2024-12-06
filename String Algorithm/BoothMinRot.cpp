#include <bits/stdc++.h>
using namespace std;

// Function to return the lexicographically minimal rotation of a string
string minimal_rotation(string s) {
    int n = s.size();
    s += s;  // Concatenate the string with itself
    vector<int> f(2 * n, -1);  // Failure function
    int k = 0;  // Least rotation of string found so far

    for (int j = 1; j < 2 * n; ++j) {
        char sj = s[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s[k + i + 1]) {
            if (sj < s[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (sj != s[k + i + 1]) {
            if (sj < s[k]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    return s.substr(k, n);  // Return the minimal rotation
}

int main() {
    string s;
    cin >> s;
    cout << minimal_rotation(s) << endl;
    return 0;
}
