#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string shots;
    cin >> shots;

    vector<int> toShoot;
    int missed = 0;
    for(int i = 0; i < n; i++) {
        if(shots[i] == '0') {
            missed++;
        } else {
            if(missed != 0) {
                toShoot.push_back(missed);
                missed = 0;
            }
        }
    }

    if(missed != 0) {
        toShoot.push_back(missed);
    }

    int leftToShoot = a - toShoot.size();
    cout << leftToShoot * (b + 1) << endl;

    for(int i = 0; i < toShoot.size(); i++) {
        int count = toShoot[i] - b;
        if(count > 0) {
            for(int j = 1; j <= b; j++) {
                cout << i * (b + 1) + j + count << " ";
            }
        } else {
            for(int j = 1; j <= toShoot[i]; j++) {
                cout << i * (b + 1) + j << " ";
            }
        }
    }

    for(int i = toShoot.size(); i < a; i++) {
        for(int j = 1; j <= b; j++) {
            cout << n - (a - i) * (b + 1) + j << " ";
        }
    }

    return 0;
}