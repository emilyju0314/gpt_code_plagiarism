#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int pages[7];
    for (int i = 0; i < 7; i++) {
        cin >> pages[i];
    }
    
    int sum = 0;
    int day = 0;
    
    while (sum < n) {
        for (int i = 0; i < 7; i++) {
            sum += pages[i];
            if (sum >= n) {
                day = i + 1;
                break;
            }
        }
    }
    
    cout << day << endl;
    
    return 0;
}