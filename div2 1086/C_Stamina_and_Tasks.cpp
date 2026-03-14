#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


void solbayri() {
    int n;
    if (!(cin >> n)) return;

    vector<pair<int, int>> tsavlue(n);
    for (int i = 0; i < n; i++) {
        cin >> tsavlue[i].first >> tsavlue[i].second;
    }

    long double max_points_from_here = 0.0;


    for (int i = n - 1; i >= 0; i--) {
        long double c = (long double)tsavlue[i].first;
        long double p_multiplier = 1.0L - (tsavlue[i].second / 100.0L);

        
        long double complete_val = c + p_multiplier * max_points_from_here;
        
        if (complete_val > max_points_from_here) {
            max_points_from_here = complete_val;
        }
    }

    cout << fixed << setprecision(10) << (double)max_points_from_here << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tescases;
    if (!(cin >> tescases)) return 0;
    while (tescases--) {
        solbayri();
    }
    return 0;
}