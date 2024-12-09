#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> packets(n);
    int total = 0;

    for(int i = 0; i < n; i++) {
        cin >> packets[i];
        total += packets[i];
    }

    vector<int> ansGrigory, ansAndrew;

    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sum += packets[i];
                ansGrigory.push_back(i + 1);
            } else {
                ansAndrew.push_back(i + 1);
            }
        }

        if(sum * 2 != total) {
            for(int i = 0; i < ansAndrew.size(); i++) {
                cout << ansAndrew[i] << " ";
            }
            cout << endl;
            return 0;
        }
        
        ansGrigory.clear();
        ansAndrew.clear();
    }

    cout << -1 << endl;

    return 0;
}