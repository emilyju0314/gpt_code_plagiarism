#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int m = 2*k + n + k*(n-1); // Calculate the minimal possible m

    cout << m << endl;

    for(int i = 0; i < n; i++) {
        vector<int> set;
        set.push_back(1 + i*k);
        set.push_back(2 + i*k);
        set.push_back(1 + 2*k + i*(k-1));
        set.push_back(1 + 2*k + i*(k-1) + 1);

        for(int j = 0; j < 4; j++) {
            cout << set[j] << " ";
        }
        cout << endl;
    }

    return 0;
}