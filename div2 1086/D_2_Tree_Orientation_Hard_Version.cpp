#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

bitset<8000> reach[8000];
int reach_sz[8000];

bool solve() {
    int n;
    if (!(cin >> n)) return false;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reach[i].reset();
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') reach[i].set(j);
        }
        reach_sz[i] = reach[i].count();
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        vector<int> candidates;
        for (int j = 0; j < n; j++) {
            if (i != j && reach[i].test(j)) {
                candidates.push_back(j);
            }
        }

        // Sort by reachability size descending to pick potential children first
        sort(candidates.begin(), candidates.end(), [](int a, int b) {
            return reach_sz[a] > reach_sz[b];
        });

        bitset<8000> covered;
        for (int v : candidates) {
            if (!covered.test(v)) {
                // Before adding edge i -> v, verify that R(v) is a subset of R(i)
                // and R(v) does not intersect with already 'covered' nodes.
                // In a tree, if reach[i] contains reach[v], (reach[i] & reach[v]) == reach[v]
                if ((reach[i] & reach[v]) == reach[v]) {
                    edges.push_back({i + 1, v + 1});
                    covered |= reach[v];
                } else {
                    return false; // Impossible reachability structure
                }
            }
        }
    }

    if (edges.size() != n - 1) return false;

    // Check connectivity
    vector<int> p(n + 1);
    for(int i=1; i<=n; i++) p[i] = i;
    auto find = [&](auto self, int i) -> int {
        return p[i] == i ? i : p[i] = self(self, p[i]);
    };
    int comps = n;
    for(auto &e : edges) {
        int u = find(find, e.first), v = find(find, e.second);
        if(u != v) { p[u] = v; comps--; }
    }
    if(comps != 1) return false;

    cout << "Yes" << endl;
    for (auto& e : edges) cout << e.first << " " << e.second << "\n";
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        if (!solve()) cout << "No" << endl;
    }
    return 0;
}