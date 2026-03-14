#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;



void solfucntion() {
    string dvalue;
    cin >> dvalue;
    
    int n = dvalue.length();
    long long current_sum = 0;
    vector<int> digits;
    
    for (int i = 0; i < n; i++) {
        int d = dvalue[i] - '0';
        current_sum += d;
        digits.push_back(d);
    }
    
    if (current_sum <= 9) {
        cout << 0 << "\n";
        return;
    }
    

    
    vector<int> redctiobaluetiion;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            redctiobaluetiion.push_back(digits[i] - 1);
        } else {
            redctiobaluetiion.push_back(digits[i] - 0);
        }
    }
    
    sort(redctiobaluetiion.rbegin(), redctiobaluetiion.rend());
    
    int moves = 0;
    long long needed_reduction = current_sum - 9;
    
    for (int r : redctiobaluetiion) {
        if (needed_reduction <= 0) break;
        needed_reduction -= r;
        moves++;
    }
    
    cout << moves << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tescasevalue;
    cin >> tescasevalue;
    while (tescasevalue--) {
        solfucntion();
    }
    return 0;
}