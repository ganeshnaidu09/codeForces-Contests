#include <bits/stdc++.h>
using namespace std;

struct Port {
    int id;
    // add attributes: capacity, type, group, etc.
};

struct Edge {
    int u, v;
    // add attributes: capacity, cost, penalty, etc.
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ===== 1) Parse input (replace with actual spec) =====
    int N = 0, M = 0;
    // cin >> N >> M;
    // vector<Port> ports; ports.reserve(N);
    // vector<Edge> edges; edges.reserve(M);

    // for (int i = 0; i < N; ++i) {
    //     ports.push_back({i});
    //     // read attributes
    // }

    // for (int i = 0; i < M; ++i) {
    //     int u, v; cin >> u >> v;
    //     edges.push_back({u, v});
    // }

    // ===== 2) Build graph / indices =====
    // vector<vector<int>> adj(N);
    // for (auto &e : edges) adj[e.u].push_back(e.v);

    // ===== 3) Baseline greedy assignment =====
    // Example: assign each port to at most one neighbor if allowed
    // vector<int> assign(N, -1);
    // vector<char> used(N, false);
    // for (int u = 0; u < N; ++u) {
    //     for (int v : adj[u]) {
    //         if (!used[v]) { assign[u] = v; used[v] = true; break; }
    //     }
    // }

    // ===== 4) Local improvements (optional) =====
    // Try swaps/reassignments to reduce conflicts or penalties
    // auto score = [&](/*state*/) -> long long {
    //     // compute score based on problem’s formula
    //     return 0;
    // };
    // // iterate a few times with random moves / hill-climbing

    // ===== 5) Output in required format =====
    // Replace with exact required format:
    // int K = 0; // number of assignments
    // for (int u = 0; u < N; ++u) if (assign[u] != -1) ++K;
    // cout << K << "\n";
    // for (int u = 0; u < N; ++u) if (assign[u] != -1) cout << u << " " << assign[u] << "\n";

    return 0;
}
