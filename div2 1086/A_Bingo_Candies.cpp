#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solavtions() {
    int nValuetoget;
    cin >> nValuetoget;
    map<int, int> countvalues;
    for (int i = 0; i < nValuetoget * nValuetoget; ++i) {
        int color;
        cin >> color;
        countvalues[color]++;
    }

    if (nValuetoget == 1) {
        cout << "NO" << endl;
        return;
    }

    for (auto const& [color, count] : countvalues) {
        if (count > nValuetoget * nValuetoget - nValuetoget) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tescasesVakue;
    cin >> tescasesVakue;
    while (tescasesVakue--) {
        solavtions();
    }
    return 0;
}