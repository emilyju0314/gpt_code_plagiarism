#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<string, int> M;

    while(q--) {
        int query;
        cin >> query;

        if(query == 0) {
            string key;
            int x;
            cin >> key >> x;
            M[key] = x;
        } else {
            string key;
            cin >> key;
            cout << M[key] << endl;
        }
    }

    return 0;
}