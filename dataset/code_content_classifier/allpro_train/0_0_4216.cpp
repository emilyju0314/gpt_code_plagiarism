#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    long long sh_count = 0, s_count = 0, total = 0;
    for (const string& str : strings) {
        for (char c : str) {
            if (c == 's') {
                s_count++;
            } else {
                sh_count += s_count;
            }
        }
    }

    total = sh_count + s_count * (s_count - 1) / 2;
    cout << total << endl;

    return 0;
}