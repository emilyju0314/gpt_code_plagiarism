#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string cards;
    cin >> cards;
    
    int count_0 = 0, count_1 = 0;
    for (int i = 0; i < k; i++) {
        if (cards[i] == '0') {
            count_0++;
        } else {
            count_1++;
        }
    }
    
    if (count_0 == k || count_1 == k) {
        cout << "tokitsukaze" << endl;
    } else if (k == 1) {
        cout << "once again" << endl;
    } else {
        bool draw = true;
        
        for (int i = k; i < n; i++) {
            if (cards[i - k] != cards[i - 1]) {
                draw = false;
                break;
            }
        }
        
        if (draw) {
            cout << "once again" << endl;
        } else {
            cout << "tokitsukaze" << endl;
        }
    }
    
    return 0;
}