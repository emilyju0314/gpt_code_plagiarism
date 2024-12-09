#include <iostream>

using namespace std;

int main() {
    int a;
    
    while(true) {
        cin >> a;
        
        if (a == 0) {
            break;
        }
        
        int cost = INT_MAX;
        
        for (int i = 0; i <= a / 200; i++) {
            for (int j = 0; j <= a / 300; j++) {
                for (int k = 0; k <= a / 500; k++) {
                    if (200 * i + 300 * j + 500 * k == a) {
                        int temp_cost = i * 380 + j * 550 + k * 850;
                        
                        if (i >= 5) {
                            temp_cost -= i * 380 * 0.2;
                        }
                        
                        if (j >= 4) {
                            temp_cost -= j * 550 * 0.15;
                        }
                        
                        if (k >= 3) {
                            temp_cost -= k * 850 * 0.12;
                        }
                        
                        cost = min(cost, temp_cost);
                    }
                }
            }
        }
        
        cout << cost << endl;
    }
    
    return 0;
}