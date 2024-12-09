#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<char, int> freq;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        freq[name[0]]++;
    }

    int max_pairs = 0;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        max_pairs += (it->second * (it->second - 1)) / 2;
    }

    int total_pairs = (n * (n - 1)) / 2;
    int min_pairs = total_pairs - max_pairs;

    cout << min_pairs << endl;

    return 0;
}