#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    unordered_map<int, int> count;
    for(int i = 0; i < n; i++) {
        count[s[i]]++;
    }

    int max_copies = 0;
    vector<int> result;
    for(auto& elem : count) {
        int num_copies = elem.second / k;
        if(num_copies > max_copies) {
            max_copies = num_copies;
            result.clear();
            for(int j = 0; j < k; j++) {
                result.push_back(elem.first);
            }
        }
    }

    for(int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }

    return 0;
}