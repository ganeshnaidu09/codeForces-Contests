#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (m == n) {
            cout << -1 << "\n";
            continue;
        }
        if (m == 0) {
            if (n == 2) {
                cout << -1 << "\n";
                continue;
            }
            cout << n << "\n";
            for (int i = 1; i <= n; i++) {
                cout << i << " " << n << "\n";
            }
            continue;
        }
        if (m == 1) {
            cout << n - 1 << "\n";
            for (int i = 1; i < n; i++) {
                cout << i << " " << n << "\n";
            }
            continue;
        }
        // m > 1
        if (m > n - 1) {
            cout << -1 << "\n";
            continue;
        }
        cout << n - m << "\n";
        for (int i = 1; i <= n - m; i++) {
            cout << i << " " << n << "\n";
        }
    }
    return 0;
}
