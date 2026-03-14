#include <iostream>

using namespace std;

void solve() {
    long long s, m;
    cin >> s >> m;

    if ((s & m) == 0) {
        cout << -1 << "\n";
        return;
    }

    long long current_sum = 0;
    long long min_n = 0;

    for (int i = 61; i >= 0; --i) {
        if ((m >> i) & 1) {
            long long bit_val = 1LL << i;
            if (s >= bit_val) {
                long long count = s / bit_val;
                min_n = max(min_n, count);
                s %= bit_val;
            }
        }
    }

    if (s > 0) {
        cout << -1 << "\n";
    } else {
        cout << min_n << "\n";
    }
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