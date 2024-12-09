#include <iostream>
#include <vector>

using namespace std;

struct Child {
    int v, d, p;
};

int main() {
    int n;
    cin >> n;

    vector<Child> children(n);

    for (int i = 0; i < n; i++) {
        cin >> children[i].v >> children[i].d >> children[i].p;
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (children[i].p < 0) continue; // Skip if confidence is already negative

        result.push_back(i + 1); // Add child to the result
        int decrease = children[i].v;
        for (int j = i + 1; j < n; j++) {
            children[j].p -= decrease;
            if (children[j].p < 0) {
                decrease = children[j].d; // Update decrease in confidence
            }
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}