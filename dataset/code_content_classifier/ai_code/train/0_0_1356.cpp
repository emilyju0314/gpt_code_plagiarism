#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string memory;
    cin >> memory;

    int dissatisfactions = 0;
    int maxDissatisfactions = 0;

    for(int i = 0; i < n; i++) {
        if(memory[i] == 'N' || memory[i] == '?') {
            dissatisfactions++;
        } else {
            dissatisfactions = 0;
        }
        maxDissatisfactions = max(maxDissatisfactions, dissatisfactions);
    }

    if(k <= maxDissatisfactions) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}