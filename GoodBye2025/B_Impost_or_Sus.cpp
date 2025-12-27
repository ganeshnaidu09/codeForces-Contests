#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;



void solve() {
    string r;
    cin >> r;
    int n = r.length();

    for (char c : r) {
        assert(c == 's' || c == 'u');
    }

    int operations = 0;

  
    if (r[0] == 'u') {
        r[0] = 's';
        operations++;
    }
    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        operations++;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (r[i] == 'u' && r[i + 1] == 'u') {
            r[i + 1] = 's';
            operations++;
        }
    }

    int s_count = 0;
    for (char c : r) if (c == 's') s_count++;
    
    if (s_count < 2) {

        operations++; 
    }

    cout << operations << endl;
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