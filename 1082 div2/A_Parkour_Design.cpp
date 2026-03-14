#include <iostream>

using namespace std;


void solve() {
    long long xavluetoget, y;
    cin >> xavluetoget >> y;

    long long rhs = xavluetoget - 2 * y;

    if (rhs < 0 || rhs % 3 != 0) {
        cout << "NO" << endl;
        return;
    }

    long long valuestoget = rhs / 3; // This is b + 2c
    long long mibvakuer = max(0LL, -y);

    if (valuestoget >= 2 * mibvakuer) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    cin >> testcases;
    while (testcases--) {
        solve();
    }
    return 0;
}