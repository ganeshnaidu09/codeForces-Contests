#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Elf {
    int id;
    long long a;
};

bool compareElves(const Elf& a, const Elf& b) {
    return a.a < b.a;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; i++) {
        elves[i].id = i + 1;
        cin >> elves[i].a;
    }

    sort(elves.begin(), elves.end(), compareElves);

    // The strongest elf (elves[n-1]) is our primary target.
    // If an elf with attack A attacks an elf with health H and attack B:
    // New health of attacker: A - B
    // New health of target: H - A
    
    // To minimize survivors, we make weaker elves attack the strongest elf.
    // Each such attack:
    // 1. The attacker (weaker) dies because its health (A) - target's attack (B) < 0.
    // 2. The target (stronger) loses health but remains alive as long as H > 0.
    
    // Let's use the strongest elf (elves[n-1]) as the target for n-m attacks.
    // But we must ensure the target stays alive until the final attack.
    // And we must ensure m elves are alive and no more attacks can happen.

    // Case: m = 0. Since the strongest elf's health is only reduced by smaller 
    // values, it's very hard to kill it without a stronger elf.
    // Actually, m can be 0 if the strongest elf is eventually killed. 
    // This happens if the sum of attacks of elves it fights exceeds its health.
    
    long long strongest_a = elves[n-1].a;
    long long sum_others = 0;
    for(int i = 0; i < n-1; ++i) sum_others += elves[i].a;

    // Check if m=0 is possible: strongest must die.
    if (m == 0) {
        if (sum_others < strongest_a) {
            cout << -1 << endl;
            return;
        }
    }

    vector<pair<int, int>> attacks;
    vector<long long> current_h(n);
    for(int i=0; i<n; ++i) current_h[i] = elves[i].a;

    // To get exactly m survivors:
    // We need to kill n-m elves.
    // We can kill i-th elf by making it attack a stronger elf.
    
    int dead_count = 0;
    int target_idx = n - 1;

    // 1. Kill n-m elves by making them attack the target (strongest)
    for (int i = 0; i < n - 1 && dead_count < n - m; i++) {
        attacks.push_back({elves[i].id, elves[target_idx].id});
        current_h[target_idx] -= elves[i].a;
        dead_count++;
    }

    // 2. If we still need to kill one more (the strongest itself), 
    // it must have been the case that m=0.
    if (dead_count < n - m) {
        // This only happens if m=0 and we haven't killed the strongest yet.
        // But the strongest cannot attack itself. It must attack one of the 
        // already 'dead' elves? No, they must be living. 
        // This logic confirms m=0 is only possible if the target dies from recoil.
        if (m == 0 && current_h[target_idx] <= 0) {
            // Strongest is already dead from recoil.
        } else {
            cout << -1 << endl;
            return;
        }
    } else {
        // We have exactly m survivors. 
        // BUT, the survivors who haven't attacked yet could still attack!
        // To terminate, all survivors (except possibly one) must have attacked.
        for (int i = n - m; i < n - 1; i++) {
            // Make them attack the target. They must survive the recoil.
            // This is possible if their attack > target's attack.
            // But target's attack is the strongest. So they will die.
            // This means we need a different approach for survivors.
        }
    }

    // Correct Approach: 
    // To keep m alive, let the strongest elf attack (n-m) elves.
    // Since strongest is bigger, victims die, strongest lives.
    // Strongest has now "attacked", so it cannot attack again.
    // The other m-1 survivors have not attacked, so they must attack 
    // the strongest to be "used up" while surviving.
    // To survive, they must attack the strongest when its health is low 
    // OR they must be the target.
    
    // Re-simplified logic that fits the example output:
    // Victims attack the strongest (and die). 
    // Survivors (who are not the strongest) must also attack to be "used".
    // To survive the recoil, the target's attack must be less than the attacker's health.
    // This is impossible if the target is the strongest.
    
    // However, if the target's health is already <= 0, the attack is invalid.
    // The termination condition: "No pair (x,y) exists where x is alive and has not attacked".
    // If only one elf is alive, it can't attack anyone else -> Terminate.
    // If multiple elves are alive, they all must have attacked.
    
    // If m = 1: Strongest attacks n-1 elves. 1 survives.
    // If m > 1: This is much harder because survivors must attack.
    
    // Looking at the example output "1 3, 2 3, 3 3":
    // The target is the same, and even the target eventually attacks itself? 
    // No, that's "x_i != y_i".
    
    cout << -1 << endl; // Place-holder for complex cases; the logic above is a starting point.
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}