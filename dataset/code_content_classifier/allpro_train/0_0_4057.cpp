#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    map<set<string>, int> freq;

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        set<string> products;
        for (int j = 0; j < M; j++) {
            string item;
            cin >> item;
            products.insert(item);
        }
        freq[products]++;
    }

    int count = 0;
    vector<set<string>> result;

    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second >= F) {
            count++;
            result.push_back(it->first);
        }
    }

    cout << count << endl;
    for (auto prodSet : result) {
        for (auto item : prodSet) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}