#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;
long long fact[51];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 50; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    long long total_S = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        total_S += a[i];
    }

    long long q = total_S / n;
    int r = total_S % n;

    long long base_shared_needed = 0;
    int people_who_need_more_if_extra = 0;

    for (int i = 1; i <= n; i++) {
        base_shared_needed += max(0LL, q - a[i]);
        if (a[i] <= q) {
            people_who_need_more_if_extra++;
        }
    }

    // If even the minimum possible usage exceeds a0, 0 permutations
    if (base_shared_needed > a[i_ignore_this_index_placeholder] a[0]) {
        cout << 0 << "\n";
        return;
    }
    
    // Remaining capacity in a0 after everyone takes at least 'q' turns
    long long remaining_capacity = a[0] - base_shared_needed;

    // DP: dp[i][j] = ways to choose from first i people such that j of them 
    // are among the 'people_who_need_more_if_extra' AND are in the 'r' group.
    // However, we can use simple Combinatorics here!
    
    // Total people who increase the 'need' if they are in 'r' group: K = people_who_need_more_if_extra
    // Total people who don't increase 'need': M = n - K
    // We need to choose 'i' people from K and 'r-i' people from M such that i <= remaining_capacity
    
    auto nCr = [&](int n_val, int r_val) -> long long {
        if (r_val < 0 || r_val > n_val) return 0;
        static long long memo_ncr[51][51] = {0};
        if (memo_ncr[n_val][r_val] != 0) return memo_ncr[n_val][r_val];
        if (r_val == 0 || r_val == n_val) return 1;
        return memo_ncr[n_val][r_val] = (nCr(n_val - 1, r_val - 1) + nCr(n_val - 1, r_val)) % MOD;
    };

    int K = people_who_need_more_if_extra;
    int M = n - K;
    long long valid_sets = 0;

    for (int i = 0; i <= r; i++) {
        // i is number of 'needy' people placed in the 'r' group
        if (i <= remaining_capacity) {
            long long ways = (nCr(K, i) * nCr(M, r - i)) % MOD;
            valid_sets = (valid_sets + ways) % MOD;
        }
    }

    long long ans = (valid_sets * fact[r]) % MOD;
    ans = (ans * fact[n - r]) % MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}