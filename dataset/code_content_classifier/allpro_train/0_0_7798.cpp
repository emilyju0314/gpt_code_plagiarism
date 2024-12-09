#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n; // number of files
    vector<string> files(n);
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    cin >> q; // number of queries
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        int count = 0;
        string suggestion = "-";
        for (int j = 0; j < n; j++) {
            if (files[j].find(query) != string::npos) {
                count++;
                suggestion = files[j];
            }
        }
        cout << count << " " << suggestion << endl;
    }

    return 0;
}