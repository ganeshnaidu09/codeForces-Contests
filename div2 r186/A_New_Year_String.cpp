#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = INT_MAX;
        // Option 1: ensure "2026" exists
        for (int i = 0; i + 4 <= n; i++) {
            int cost = 0;
            string target = "2026";
            for (int j = 0; j < 4; j++) {
                if (s[i+j] != target[j]) cost++;
            }
            ans = min(ans, cost);
        }
        // Option 2: remove all "2025"
        int cost_remove = 0;
        for (int i = 0; i + 4 <= n; i++) {
            if (s.substr(i,4) == "2025") {
                cost_remove++;
            }
        }
        ans = min(ans, cost_remove);
        cout << ans << "\n";
    }
    return 0;
}
