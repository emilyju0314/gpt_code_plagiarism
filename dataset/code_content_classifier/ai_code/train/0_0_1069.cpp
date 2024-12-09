#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> truth(n, 0); // counts how many times each suspect tells the truth
    vector<int> lie(n, 0); // counts how many times each suspect tells a lie

    for (int i = 0; i < n; i++) {
        string answer;
        cin >> answer;

        int ai;
        cin >> ai;

        if (answer[0] == '+') {
            truth[ai - 1]++;
        } else {
            lie[ai - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (truth[i] > 0 && lie[i] == 0) {
            cout << "Truth" << endl;
        } else if (truth[i] == 0 && lie[i] > 0) {
            cout << "Lie" << endl;
        } else {
            cout << "Not defined" << endl;
        }
    }

    return 0;
}