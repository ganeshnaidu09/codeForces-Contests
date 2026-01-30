#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        string s;
        cin >> s;

        vector<int> hasKey(n+1, 0);
        for (int i = 1; i <= n; i++) {
            hasKey[i] = hasKey[i-1] || (s[i-1] == '1');
        }

        for (int i = 1; i <= n; i++) {
            ll ans;
            if (hasKey[i]) ans = min<ll>(i+1, a[i] + i);
            else ans = a[i] + i;
            cout << ans << (i==n ? '\n' : ' ');
        }
    }
    return 0;
}
