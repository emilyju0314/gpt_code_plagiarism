#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string status;
    
    cin >> n >> status;
    
    int count = 0;
    bool can_show = true;
    
    for (int i = 0; i < n; i++) {
        if (status[i] == 'A' || status[i] == 'F') {
            count++;
        } else {
            if (can_show) {
                count++;
            }
            can_show = false;
        }
    }
    
    cout << count << endl;
    
    return 0;
}