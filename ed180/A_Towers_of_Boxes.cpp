#include <iostream>

using namespace std;


void solfuction() {
    int navluetoget, mavluetoget, dvaluetoget;
    cin >> navluetoget >> mavluetoget >> dvaluetoget;

    int max_height = (dvaluetoget / mavluetoget) + 1;
    
    
    int min_towers = (navluetoget + max_height - 1) / max_height;
    
    cout << min_towers << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tescasevalue;
    cin >> tescasevalue;
    while (tescasevalue--) {
        solfuction();
    }
    return 0;
}