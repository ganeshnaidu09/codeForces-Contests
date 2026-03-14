#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tescasevalie;
    cin >> tescasevalie;
    while (tescasevalie--) {
        int navluetoget, mavluetoget;
        cin >> navluetoget >> mavluetoget;
        vector<int> avluetoget(navluetoget), bavluetoget(mavluetoget);
        for (int i = 0; i < navluetoget; i++) cin >> avluetoget[i];
        for (int j = 0; j < mavluetoget; j++) cin >> bavluetoget[j];

        int dividedvakue = 0, novaluetoget = 0;
        for (int y : bavluetoget) {
            bool ok = false;
            for (int x : avluetoget) {
                if (y % x == 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) dividedvakue++;
            else novaluetoget++;
        }

        if (dividedvakue == 0) cout << "Bob\n";
        else if (novaluetoget == 0) cout << "Alice\n";
        else {
            if (dividedvakue > novaluetoget) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
    return 0;
}
