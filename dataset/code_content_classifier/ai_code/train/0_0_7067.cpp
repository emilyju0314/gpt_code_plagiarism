#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int maxDay = 0;
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        if (s > maxDay) {
            maxDay = s;
        } else {
            while (s <= maxDay) {
                s += d;
            }
        }
        maxDay = s;
    }
    
    cout << maxDay << endl;
    
    return 0;
}