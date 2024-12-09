#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    if (k > 500000000) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> sequence;

    if (k % 2 == 1) {
        sequence.push_back(k);
        sequence.push_back(k);
        k--;
    }
    
    int n = 2;
    while (k > 0) {
        sequence.push_back(k);
        sequence.push_back(-k);
        k -= 2;
        n += 2;
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}