#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> grigory(n);
    for(int i = 0; i < n; i++) {
        cin >> grigory[i];
    }

    vector<int> andrew(n);
    for(int i = 0; i < n; i++) {
        cin >> andrew[i];
    }

    if(n == 2) {
        if(grigory[0] == andrew[0] && grigory[1] == andrew[1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        bool possible = false;
        if((andrew[0] - grigory[0]) % 2 == 0) {
            for(int i = 1; i < n - 1; i++) {
                if(grigory[i-1] + grigory[i+1] - grigory[i] == andrew[i]) {
                    possible = true;
                    break;
                }
            }
        }

        if(possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}