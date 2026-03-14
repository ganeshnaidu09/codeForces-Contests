#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;

    // range[0] tracks [min, max] for even L
    // range[1] tracks [min, max] for odd L
    int min_L[2] = {0, INF};
    int max_L[2] = {0, -INF};

    for (int i = 0; i < n; ++i) {
        int next_min[2] = {INF, INF};
        int next_max[2] = {-INF, -INF};

        for (int p = 0; p < 2; ++p) {
            if (min_L[p] > max_L[p]) continue;

            // Option 1: Take from LEFT
            // The character is T[L+1]. Parity of L+1 determines if it's 'a' or 'b'.
            // If L is parity p, L+1 is parity 1-p.
            // T[pos] is 'a' if pos is odd, 'b' if pos is even.
            int pos_L = min_L[p] + 1; 
            char char_L = (pos_L % 2 != 0) ? 'a' : 'b';
            if (x[i] == '?' || x[i] == char_L) {
                next_min[1 - p] = min(next_min[1 - p], min_L[p] + 1);
                next_max[1 - p] = max(next_max[1 - p], max_L[p] + 1);
            }

            // Option 2: Take from RIGHT
            // The character is T[n - (i - L)].
            // Note: L parity stays the same.
            // We must check if the char_R is consistent for the whole range [min_L[p], max_L[p]].
            // Since T alternates, T[n-i+L] parity depends on (n-i+L).
            // For a fixed parity of L, (n-i+L) has a fixed parity!
            int pos_R = n - (i - min_L[p]);
            char char_R = (pos_R % 2 != 0) ? 'a' : 'b';
            if (x[i] == '?' || x[i] == char_R) {
                next_min[p] = min(next_min[p], min_L[p]);
                next_max[p] = max(next_max[p], max_L[p]);
            }
        }

        min_L[0] = next_min[0]; max_L[0] = next_max[0];
        min_L[1] = next_min[1]; max_L[1] = next_max[1];

        if (min_L[0] > max_L[0] && min_L[1] > max_L[1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}