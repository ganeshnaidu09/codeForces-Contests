#include <bits/stdc++.h>
using namespace std;

unsigned int nearestValid(unsigned int val, unsigned int mask) {
    // Find nearest integer to val that has no common bits with mask
    // Try downward and upward search
    unsigned int down = val;
    while (down > 0 && (down & mask)) down--;
    unsigned int up = val;
    while ((up & mask)) up++;
    // Choose closer one
    if (val - down <= up - val) return down;
    return up;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        unsigned int x, y;
        cin >> x >> y;

        if ((x & y) == 0) {
            cout << x << " " << y << "\n";
            continue;
        }

        // Option 1: fix y, adjust p
        unsigned int p1 = nearestValid(x, y);
        unsigned int q1 = y;
        long long cost1 = abs((long long)x - (long long)p1);

        // Option 2: fix x, adjust q
        unsigned int p2 = x;
        unsigned int q2 = nearestValid(y, x);
        long long cost2 = abs((long long)y - (long long)q2);

        if (cost1 <= cost2) {
            cout << p1 << " " << q1 << "\n";
        } else {
            cout << p2 << " " << q2 << "\n";
        }
    }
    return 0;
}
