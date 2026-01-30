#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int initial = 0;
        for (char c : s) if (c == '1') initial++;

        int total = initial;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                int len = j - i;
                bool leftOccupied = (i > 0 && s[i-1] == '1');
                bool rightOccupied = (j < n && s[j] == '1');
                if (leftOccupied && rightOccupied) {
                    total += (len - 1) / 2; // middle segment
                } else {
                    total += (len + 1) / 2; // edge segment
                }
                i = j;
            } else {
                i++;
            }
        }

        cout << total << "\n";
    }
    return 0;
}
