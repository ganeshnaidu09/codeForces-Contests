#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Precompute run lengths
        vector<int> run(n,1);
        for (int i = n-2; i >= 0; i--) {
            if (a[i+1] == a[i]+1) run[i] = run[i+1]+1;
        }

        // Total sum of lengths + number of subsegments
        ll totalSubs = 1LL*n*(n+1)/2;
        ll sumLengths = 1LL*n*(n+1)*(n+2)/6;
        ll base = sumLengths + totalSubs;

        // Subtract contributions of maxRun
        // Use stack to assign each run length as maximum
        ll subtract = 0;
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && run[st.back()] <= run[i]) {
                int j = st.back(); st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int right = i;
                // run[j] is maximum for subsegments covering j..j+run[j]-1
                // with left<j and right>=i
                int L = j - left;
                int R = right - j;
                subtract += 1LL * run[j] * L * R;
            }
            st.push_back(i);
        }
        while (!st.empty()) {
            int j = st.back(); st.pop_back();
            int left = st.empty() ? -1 : st.back();
            int right = n;
            int L = j - left;
            int R = right - j;
            subtract += 1LL * run[j] * L * R;
        }

        cout << base - subtract << "\n";
    }
    return 0;
}
