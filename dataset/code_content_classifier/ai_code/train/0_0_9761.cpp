#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h;
    cin >> h;

    vector<int> seq(h+1);
    for (int i = 0; i <= h; i++) {
        cin >> seq[i];
    }

    bool ambiguous = false;
    for (int i = 1; i <= h; i++) {
        if (seq[i] > 1 && seq[i-1] > 1) {
            ambiguous = true;
            break;
        }
    }

    if (!ambiguous) {
        cout << "perfect" << endl;
    } else {
        cout << "ambiguous" << endl;
        bool first = true;
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j < seq[i]; j++) {
                if (j > 0) {
                    cout << " ";
                }
                if (i > 0 && j == 1) {
                    cout << (first ? i-1 : i);
                } else {
                    cout << i;
                }
            }
            cout << endl;
            if (i > 0 && seq[i] > 1) {
                first = false;
            }
        }
    }

    return 0;
}