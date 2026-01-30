#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    // dp[parity] = {total_strings, sum_of_last_c, sum_of_f_prefix}
    // We use long long for intermediate sums and apply MOD carefully.
    ll count[2] = {0, 0};
    ll sum_c[2] = {0, 0};
    ll sum_f[2] = {0, 0};

    // Initial state: 1 string of length 0, c_0 = 0, f(r) = 0, parity = 0
    count[0] = 1;

    for (int i = 0; i < n; i++) {
        ll n_count[2] = {0, 0};
        ll n_sum_c[2] = {0, 0};
        ll n_sum_f[2] = {0, 0};

        for (int p = 0; p < 2; p++) {
            if (count[p] == 0) continue;

            // Option: Current bit is '0'
            if (s[i] == '0' || s[i] == '?') {
                // c_i = c_{i-1} + x. Parity remains p.
                n_count[p] = (n_count[p] + count[p]) % MOD;
                ll cur_c = (sum_c[p] + (count[p] * (x % MOD)) % MOD) % MOD;
                n_sum_c[p] = (n_sum_c[p] + cur_c) % MOD;
                n_sum_f[p] = (n_sum_f[p] + sum_f[p] + cur_c) % MOD;
            }

            // Option: Current bit is '1'
            if (s[i] == '1' || s[i] == '?') {
                // c_i = y - c_{i-1}. Parity flips to 1-p.
                int np = 1 - p;
                n_count[np] = (n_count[np] + count[p]) % MOD;
                ll cur_c = ((count[p] * (y % MOD)) % MOD - sum_c[p] + MOD) % MOD;
                n_sum_c[np] = (n_sum_c[np] + cur_c) % MOD;
                n_sum_f[np] = (n_sum_f[np] + sum_f[p] + cur_c) % MOD;
            }
        }
        
        for(int p = 0; p < 2; p++) {
            count[p] = n_count[p];
            sum_c[p] = n_sum_c[p];
            sum_f[p] = n_sum_f[p];
        }
    }

    cout << (sum_f[0] + sum_f[1]) % MOD << "\n";
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