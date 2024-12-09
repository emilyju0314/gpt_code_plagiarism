#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for(int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(permutation[i] > permutation[j]) {
                count++;
            }
        }
    }

    if(count % 2 == 0) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }

    return 0;
}