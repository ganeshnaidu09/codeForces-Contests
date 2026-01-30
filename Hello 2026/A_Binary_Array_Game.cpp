#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Alice wins if she can force the final element to be 0.
 * A 0 is created only if a subarray of all 1s is compressed.
 * If any 0 exists in a chosen subarray, the result is 1.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones++;
        else zeros++;
    }

    // Alice wins if she can force the final reduction to be 1-min(1,1...) = 0.
    // Through game theory analysis of this specific reduction:
    // Alice wins if the total number of 1s is greater than or equal to the 
    // number of 0s in a way that she can neutralize the 0s.
    
    if (ones >= zeros) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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