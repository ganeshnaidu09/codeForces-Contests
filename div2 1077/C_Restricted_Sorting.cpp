#include <bits/stdc++.h>
using namespace std;

/*
Restricted Sorting:
We need the largest k such that we can sort the array using swaps where |ai - aj| >= k.

Key idea:
- If the array is already sorted, answer is -1 (since no swaps needed).
- Otherwise, we must find the minimum absolute difference between any element
  that is "out of place" compared to the sorted array.
- Let b = sorted(a). For each i, if a[i] != b[i], then we need to move a[i].
  The largest k possible is the minimum |a[i] - b[i]| over all mismatched positions.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());

        if (a == b) {
            cout << -1 << "\n";
            continue;
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                ans = min(ans, abs(a[i] - b[i]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
