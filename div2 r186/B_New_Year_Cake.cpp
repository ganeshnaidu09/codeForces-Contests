#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long ans = 0;
        // Try both starting colors: top layer white or dark
        for (int start = 0; start < 2; start++) {
            long long wa = a, da = b;
            long long size = 1;
            long long layers = 0;
            int color = start; // 0 = white, 1 = dark
            while (true) {
                if (color == 0) {
                    if (wa < size) break;
                    wa -= size;
                } else {
                    if (da < size) break;
                    da -= size;
                }
                layers++;
                size *= 2;
                color ^= 1;
            }
            ans = max(ans, layers);
        }
        cout << ans << "\n";
    }
    return 0;
}
