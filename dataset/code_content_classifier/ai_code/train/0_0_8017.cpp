#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    char letter = 'a';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c[i]; j++) {
            for (int k = 0; k < i+1; k++) {
                cout << letter;
            }
            letter++;
        }
    }

    cout << endl;

    return 0;
}