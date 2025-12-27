#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        long long total = pref[n];
        long long ans = LLONG_MIN;

        for (int k = 0; k < n; k++) {
            long long left = pref[k];
            long long right = total - pref[k + 1];
            ans = max(ans, left - right);
        }

        cout << ans << "\n";
    }
    return 0;
}
