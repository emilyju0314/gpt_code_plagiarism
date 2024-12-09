#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    unordered_map<string, int> freq;
    for (int i = 0; i < s.length(); i++) {
        string temp = s.substr(i) + s.substr(0, i);
        freq[temp]++;
    }

    for (int i = 0; i < n; i++) {
        string xi;
        cin >> xi;

        int count = 0;
        for (int j = 0; j < xi.length(); j++) {
            string temp = xi.substr(j) + xi.substr(0, j);
            count += freq[temp];
        }

        cout << count << endl;
    }

    return 0;
}