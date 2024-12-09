#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    int possibleX = 0;
    int minX = n, maxX = 1;

    for(int i = 0; i < n; i++) {
        if(perm[i] < minX) {
            minX = perm[i];
        }
        if(perm[i] > maxX) {
            maxX = perm[i];
        }
    }

    if(perm[0] == minX && perm[n-1] == maxX) {
        possibleX++;
    }

    cout << possibleX << endl;

    return 0;
}