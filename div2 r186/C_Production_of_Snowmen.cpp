#include <bits/stdc++.h>
using namespace std;

// Check if rotation of X is strictly less than rotation of Y
vector<int> validationchecking(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
    vector<int> res;
    for (int shift = 0; shift < n; shift++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!(X[i] < Y[(i+shift)%n])) {
                ok = false;
                break;
            }
        }
        if (ok) res.push_back(shift);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> A(n), B(n), C(n);
        for (int i=0;i<n;i++) cin >> A[i];
        for (int i=0;i<n;i++) cin >> B[i];
        for (int i=0;i<n;i++) cin >> C[i];

        auto ab = validationchecking(A,B);
        auto bc = validationchecking(B,C);

        // For each i (rotation of A), j (rotation of B), k (rotation of C),
        // we need j-i in ab and k-j in bc.
        long long ans = 0;
        vector<bool> goodAB(n,false), goodBC(n,false);
        for (int x: ab) goodAB[x]=true;
        for (int x: bc) goodBC[x]=true;

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (!goodAB[(j-i+n)%n]) continue;
                for (int k=0;k<n;k++) {
                    if (goodBC[(k-j+n)%n]) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
