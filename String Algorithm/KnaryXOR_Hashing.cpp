
//K-nary XOR Hashing
//https://codeforces.com/contest/1418/problem/G
long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

int main() {
    using hash_t = uint64_t;

    int N;
    cin >> N;
    vector<hash_t> hash_values(N + 1);

    for (int i = 0; i <= N; i++)
        hash_values[i] = rng();

    vector<int> freq(N + 1, 0);
    vector<queue<int>> indices(N + 1);
    vector<hash_t> hashes(N + 1, 0);
    unordered_map<hash_t, int> hash_freq;
    hash_freq[hashes[0]]++;
    int64_t answer = 0;
    int start = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (indices[a].size() >= 3) {
            int remove = indices[a].front(); indices[a].pop();

            while (start <= remove) {
                hash_freq[hashes[start]]--;
                start++;
            }
        }

        int before = freq[a];
        freq[a] = (freq[a] + 1) % 3;
        hashes[i + 1] = hashes[i] + (freq[a] - before) * hash_values[a];
        answer += hash_freq[hashes[i + 1]];
        hash_freq[hashes[i + 1]]++;
        indices[a].push(i);
    }

    cout << answer << '\n';
}
