#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coefficients(n+1);
    for(int i = 0; i <= n; i++) {
        string coefficient;
        cin >> coefficient;
        if(coefficient == "?") {
            coefficients[i] = -1;
        } else {
            coefficients[i] = stoi(coefficient);
        }
    }
    
    bool can_win = false;
    
    if(n % 2 == 0) {
        if(abs(k) % 2 == 1) {
            can_win = true;
        } else {
            bool parity = false;
            for(int i = 0; i <= n; i++) {
                if(coefficients[i] == -1) {
                    parity = !parity;
                }
            }
            can_win = parity;
        }
    } else {
        if(abs(k) % 2 == 0) {
            can_win = true;
        } else {
            bool parity = false;
            for(int i = 0; i <= n; i++) {
                if(coefficients[i] == -1) {
                    parity = !parity;
                }
            }
            can_win = parity;
        }
    }
    
    if(can_win) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}