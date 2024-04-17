
// Function to build the sparse table
vector<vector<ll>> buildSparseTable(vector<ll>& arr) {
    ll n = arr.size();
    ll k = log2(n) + 1;
    vector<vector<ll>> sparseTable(n, vector<ll>(k, -1e9));

    // Initialize sparse table for range with length 1
    for (ll i = 0; i < n; i++) {
        sparseTable[i][0] = arr[i];
    }

    // Build sparse table
    for (ll j = 1; (1LL << j) <= n; j++) {
        for (ll i = 0; (i + (1LL << j) - 1) < n; i++) {
            sparseTable[i][j] = max(sparseTable[i][j - 1], sparseTable[i + (1LL << (j - 1))][j - 1]);
        }
    }

    return sparseTable;
}

// Function to query the maximum value in a range
ll queryMax(vector<vector<ll>>& sparseTable, ll l, ll r) {
    ll k = log2(r - l + 1);
    return max(sparseTable[l][k], sparseTable[r - (1LL << k) + 1][k]);
}