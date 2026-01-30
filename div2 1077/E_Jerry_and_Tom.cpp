#include <bits/stdc++.h>
using namespace std;

/*
Jerry and Tom problem solution.
We exploit the laminar property of extra edges.
Observation: Tom needs at most 1 move to force a win.
We count contributions interval by interval.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].first >> edges[i].second;
        }

        // Sort edges by start
        sort(edges.begin(), edges.end());

        long long ans = 0;

        // For each extra edge (u,v):
        // Jerry starting in [u,v-1] is forced to go to v.
        // Tom at v wins with 0 moves (if y=v).
        // Tom at any y < v can jump to v in 1 move.
        // Count contributions accordingly.
        for (auto [u,v] : edges) {
            // Jerry can start at x in [u, v-1]
            int len = v - u; // number of possible x
            // For each such x, Tom at y=v wins with 0 moves
            ans += len; // f(x,v)=0, but counted as Tom wins
            // For each such x, Tom at y<u can jump to v with 1 move
            ans += 1LL * len * (u-1);
        }

        cout << ans << "\n";
    }
    return 0;
}
