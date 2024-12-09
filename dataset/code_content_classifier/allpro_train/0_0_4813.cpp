#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> c(n);
    vector<int> w(n);
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    int total_dissatisfaction = 0;
    int total_notes = 0;
    int total_coins = 0;
    
    cout << "Amount of minimum possible total dissatisfaction of the cashier: ";
    for (int i = 0; i < n; i++) {
        total_dissatisfaction += w[i] * ((c[i] + total_notes + total_coins - m) / 100);
        int notes = (c[i] + total_notes + total_coins - m) / 100;
        int coins = (c[i] + total_notes + total_coins - m) % 100;
        
        cout << notes << " " << coins << endl;
        
        total_notes = notes;
        total_coins = coins;
    }
    
    cout << total_dissatisfaction << endl;
    
    return 0;
}