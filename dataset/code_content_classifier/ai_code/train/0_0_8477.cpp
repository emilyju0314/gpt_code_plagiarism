#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p1, p2;
    while (cin >> n >> p1 >> p2) {
        if (n == 0 && p1 == 0 && p2 == 0) {
            break;
        }
        
        vector<int> divines;
        vector<int> tribes(p1 + p2 + 1, 0);
        
        bool impossible = false;
        for (int i = 0; i < n; i++) {
            int xi, yi;
            string ai;
            cin >> xi >> yi >> ai;
            
            if (ai == "yes") {
                tribes[xi] = 1;
                tribes[yi] = 1;
            } else {
                if (tribes[xi] == -1 || tribes[yi] == -1) {
                    impossible = true;
                }
                
                if (tribes[xi] == 1) {
                    tribes[yi] = -1;
                }
                
                if (tribes[yi] == 1) {
                    tribes[xi] = -1;
                }
            }
        }
        
        if (impossible) {
            cout << "no" << endl;
        } else {
            for (int i = 1; i <= p1 + p2; i++) {
                if (tribes[i] == 1) {
                    divines.push_back(i);
                }
            }
            
            sort(divines.begin(), divines.end());
            
            for (int divine : divines) {
                cout << divine << endl;
            }
            cout << "end" << endl;
        }
    }
    
    return 0;
}