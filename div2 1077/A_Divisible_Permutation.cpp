#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> used(n + 1, false);

    // Start with the largest index constraint (n-1)
    // A simple valid pattern is often starting with n and 1
    p[n-1] = 1;
    used[1] = true;

    for (int i = n - 2; i >= 0; --i) {
        int step = i + 1;
        bool found = false;
        // Look for an unused number that satisfies |p[i] - p[i+1]| % (i+1) == 0
        for (int val = 1; val <= n; ++val) {
            if (!used[val] && abs(val - p[i+1]) % step == 0) {
                p[i] = val;
                used[val] = true;
                found = true;
                break;
            }
        }
        // Fallback for general construction if the greedy path fails
        if (!found) {
            for (int val = 1; val <= n; ++val) {
                if (!used[val]) {
                    p[i] = val;
                    used[val] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}