#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, age;
    
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        vector<int> count(7, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> age;
            if (age < 10) {
                count[0]++;
            } else if (age < 20) {
                count[1]++;
            } else if (age < 30) {
                count[2]++;
            } else if (age < 40) {
                count[3]++;
            } else if (age < 50) {
                count[4]++;
            } else if (age < 60) {
                count[5]++;
            } else {
                count[6]++;
            }
        }
        
        for (int i = 0; i < 7; i++) {
            cout << count[i] << endl;
        }
    }
    
    return 0;
}