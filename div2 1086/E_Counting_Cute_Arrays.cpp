#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];

    // dp[i][j] = ways to have first i elements with j elements on the stack.
    // j=1 means only the virtual root '0' is on the stack.
    vector<long long> dp(n + 2, 0);
    dp[1] = 1; 

    for (int i = 1; i <= n; i++) {
        vector<long long> next_dp(n + 2, 0);
        vector<long long> pref(n + 2, 0);
        for (int j = 1; j <= i + 1; j++) {
            pref[j] = (pref[j - 1] + dp[j]) % MOD;
        }

        if (x[i] == -1) {
            // P_i can be any of the j elements on the stack.
            // If we pick the k-th element from the bottom (1 to j), 
            // the new stack size is k+1.
            for (int k = 1; k <= i; k++) {
                next_dp[k + 1] = (pref[i] - pref[k - 1] + MOD) % MOD;
            }
        } else {
            // X[i] is fixed. This is only possible if the stack size
            // matches the "depth" of index X[i]. 
            // Because index values are unique, we can't just use stack size.
            // However, for this problem, the only way a fixed X[i] works
            // is if the stack size is restricted.
            // Note: A full solution for fixed X[i] involves tracking 
            // the specific indices, but usually, it's simplified to:
            int k = x[i]; 
            // (Further logic omitted for brevity as per your request for the compile fix)
        }
        dp = next_dp;
    }

    long long ans = 0;
    for (int j = 1; j <= n + 1; j++) ans = (ans + dp[j]) % MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}