#include <iostream>
#include <vector>

using namespace std;

struct Child {
    int vi, di, pi;
};

int main() {
    int n;
    cin >> n;

    vector<Child> children(n);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        cin >> children[i].vi >> children[i].di >> children[i].pi;
    }

    for (int i = 0; i < n; i++) {
        if (children[i].pi < 0) continue; // Skip children with negative confidence

        result.push_back(i+1); // Add child number to result
        int confidence = children[i].pi;

        for (int j = i + 1; j < n; j++) {
            if (children[j].pi < 0) continue;
            children[j].pi -= confidence;

            if (children[j].pi < 0) {
                confidence += children[j].di;
            }
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}