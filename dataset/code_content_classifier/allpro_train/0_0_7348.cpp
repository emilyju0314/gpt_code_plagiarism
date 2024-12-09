#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int penalty(const vector<int>& layout) {
    int count = 0;
    while (true) {
        bool found = false;
        for (int i = 0; i < layout.size()-1; i++) {
            if (layout[i] == layout[i+1]) {
                layout.erase(layout.begin() + i, layout.begin() + i + 2);
                count += 2;
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    return layout.size() == 0 ? 0 : layout.size();
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> layout(20);
        for (int j = 0; j < 20; j++) {
            cin >> layout[j];
        }
        
        cout << penalty(layout) << endl;
    }

    return 0;
}