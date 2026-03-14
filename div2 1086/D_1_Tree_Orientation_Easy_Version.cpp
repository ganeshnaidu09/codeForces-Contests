#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solavtion() {
    int navlue;
    cin >> navlue;
    vector<string> svalue(navlue);
    vector<vector<int>> adjectedvalye(navlue, vector<int>(navlue));
    for (int i = 0; i < navlue; i++) {
        cin >> svalue[i];
        for (int j = 0; j < navlue; j++) {
            adjectedvalye[i][j] = svalue[i][j] - '0';
        }
    }


    vector<pair<int, int>> edges;
    for (int u = 0; u < navlue; u++) {
        for (int v = 0; v < navlue; v++) {
            if (u == v || !adjectedvalye[u][v]) continue;

            bool direct = true;
            for (int w = 0; w < navlue; w++) {
                if (w == u || w == v) continue;
                if (adjectedvalye[u][w] && adjectedvalye[w][v]) {
                    direct = false;
                    break;
                }
            }
            if (direct) {
                edges.push_back({u + 1, v + 1});
            }
        }
    }

    if (edges.size() != navlue - 1) {
        cout << "No" << endl;
        return;
    }

    vector<vector<int>> reach(navlue, vector<int>(navlue, 0));
    for (int i = 0; i < navlue; i++) reach[i][i] = 1;
    for (auto& e : edges) reach[e.first - 1][e.second - 1] = 1;

    for (int k = 0; k < navlue; k++) {
        for (int i = 0; i < navlue; i++) {
            for (int j = 0; j < navlue; j++) {
                if (reach[i][k] && reach[k][j]) reach[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < navlue; i++) {
        for (int j = 0; j < navlue; j++) {
            if (reach[i][j] != adjectedvalye[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }

    vector<vector<int>> undir(navlue);
    for (auto& e : edges) {
        undir[e.first - 1].push_back(e.second - 1);
        undir[e.second - 1].push_back(e.first - 1);
    }
    
    vector<bool> visited(navlue, false);
    vector<int> q;
    q.push_back(0);
    visited[0] = true;
    int head = 0;
    while(head < q.size()){
        int curr = q[head++];
        for(int neighbor : undir[curr]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push_back(neighbor);
            }
        }
    }

    if (q.size() != navlue) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    for (auto& e : edges) {
        cout << e.first << " " << e.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tescases;
    cin >> tescases;
    while (tescases--) {
        solavtion();
    }
    return 0;
}