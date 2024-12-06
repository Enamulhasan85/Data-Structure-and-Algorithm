#include <bits/stdc++.h>
#define endl '\n'

using ll = long long;
using namespace std;

const int MAX_N = 6e5+5, SIGMA = 26;

int nodes = 1;
int trie[MAX_N][SIGMA], fail[MAX_N], nxt[MAX_N], seen[MAX_N], ans[MAX_N], isEnd[MAX_N];
vector<int> leaf[MAX_N], occ[MAX_N], g[MAX_N];
// fail[u]=the failure link for node
// seen[u]=check if a node has been visited in trie
// ans[i]=the number of occurrences of word i
// leaf[node] stores the indices of the words ending in node

void add_word(const string &word, const int &idx) {
    int node = 1;
    for (char ch : word) {
        if (trie[node][ch - 'a'] == 0)
            trie[node][ch - 'a'] = ++nodes;
        node = trie[node][ch - 'a'];
    }
    isEnd[node] = idx;
    leaf[node].push_back(idx);
}

/** BFS to building the failure and suffix links */
void build() {
    queue<int> q;
    int node = 1;
    fail[node] = 1;
    for (int i = 0; i < SIGMA; i++) {
        if (trie[node][i]) {
            fail[trie[node][i]] = node;
            q.push(trie[node][i]);
        }
        else trie[node][i] = 1;
    }

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int i = 0; i < SIGMA; i++) {
            if (trie[node][i]) {
                fail[trie[node][i]] = trie[fail[node]][i];
                q.push(trie[node][i]);
            }
            else trie[node][i] = trie[fail[node]][i];
        }
    }

    //Next fail link that has an endpoint of a word
    /*vector<int> inQue(MAX_N);
    inQue[1] = 1;
    nxt[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if(~isEnd[fail[node]]) nxt[node] = fail[node];
        else nxt[node] = nxt[fail[node]];
        for (int i = 0; i < SIGMA; i++) {
            if (trie[node][i] and !inQue[trie[node][i]]) {
                q.push(trie[node][i]);
                inQue[trie[node][i]] = 1;
            }
        }
    }*/

    for (int i = 2; i <= nodes; i++)
        g[fail[i]].push_back(i);
}

void search(string &s) {
    int node = 1, idx = 1;
    for (char ch : s) {
        node = trie[node][ch - 'a'];
        seen[node]++;

        //Indexes of occurrences
        //for(int i=node; i; i=nxt[i])
        //    if(~isEnd[i]) occ[isEnd[i]].push_back(idx);
        idx++;
    }
}

int dfs(int node) {
    int sol = seen[node];
    for (int son : g[node]) sol += dfs(son);
    for (int idx : leaf[node]) ans[idx] = sol;
    return sol;
}


int main() {
	ll j, i, n;

    string s;
    cin >> s >> n;

    vector<string> vs(n);
    memset(isEnd, -1, sizeof(isEnd));
    for(i=0;i<n;i++){
        cin >> vs[i];
		add_word(vs[i], i);
    }

	build();
	search(s);
	dfs(1);

	for (int i = 0; i < n; i++) {
        //cout << occ[i].size() << endl;
        //for(auto x : occ[i]) cout << x-vs[i].size()+1 << " ";
        if(ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
