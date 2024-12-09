#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> indices(k);
    for(int i = 1; i <= k; i++) {
        indices[i-1] = i;
    }

    cout << "? ";
    for(int i = 0; i < k; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
    cout.flush();

    int pos, val;
    cin >> pos >> val;

    vector<int> elements(k);
    elements[val-1] = 1;

    while(true) {
        int zeroes = 0;
        for(int i = 0; i < k; i++) {
            if(elements[i] == 0) {
                zeroes++;
                indices[zeroes-1] = i+1;
            }
        }

        if(zeroes == 0) {
            break;
        }

        cout << "? ";
        for(int i = 0; i < k - zeroes; i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
        cout.flush();

        cin >> pos >> val;
        elements[val-1] = 1;
    }

    int m;
    for(int i = 0; i < k; i++) {
        if(elements[i] == 0) {
            m = i+1;
            break;
        }
    }

    cout << "! " << m << endl;
    cout.flush();

    return 0;
}