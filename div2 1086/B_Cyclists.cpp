#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dq stores the costs of cards in their current deck order
    // win_idx is the current 0-indexed position of our target card
    deque<int> dq;
    int win_val = a[p-1];
    
    // We'll track the win card by its value and a unique flag if needed, 
    // but since we only care about its position, let's use its index.
    for(int x : a) dq.push_back(x);
    
    int win_pos = p - 1;
    ll total_wins = 0;
    ll current_m = m;

    multiset<int> top_k;
    for(int i = 0; i < k; i++) {
        top_k.insert(dq[i]);
    }

    while (true) {
        while (win_pos >= k) {
            int cheapest = *top_k.begin();
            if (current_m < cheapest) {
                cout << total_wins << "\n";
                return;
            }
            current_m -= cheapest;
          
            top_k.erase(top_k.begin());

            
            int played_val;
            if (win_pos != 0) {
                played_val = dq.front();
                dq.pop_front();
                dq.push_back(played_val);
                win_pos--;
            } else {

                played_val = dq.front();
                dq.pop_front();
                dq.push_back(played_val);
                win_pos--;
            }
            top_k.insert(dq[k-1]);
        }


        if (current_m < win_val) break;
        current_m -= win_val;
        total_wins++;

   
        auto it = dq.begin() + win_pos;
        dq.erase(it);
        dq.push_back(win_val);
        

        top_k.clear();
        for(int i = 0; i < k; i++) top_k.insert(dq[i]);
        win_pos = n - 1;

    }

    cout << total_wins << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}