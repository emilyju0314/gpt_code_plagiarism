#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> groups(k);
    for(int i = 0; i < k; i++) {
        cin >> groups[i];
    }

    int total_seats = n * 8;
    int total_soldiers = 0;
    for(int i = 0; i < k; i++) {
        total_soldiers += groups[i];
    }

    if(total_soldiers > total_seats) {
        cout << "NO" << endl;
    } else {
        bool possible = true;
        for(int i = 0; i < k; i++) {
            int remainder = groups[i] % 2;
            total_seats -= groups[i] / 2 * 2;
            if(total_seats < 0) {
                possible = false;
                break;
            }
        }
        
        if(total_seats < k) {
            possible = false;
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}