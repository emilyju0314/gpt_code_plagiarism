#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rickSet(n, 0);
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        rickSet[x - 1] = 1;
    }

    vector<int> mortySet(n, 0);
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        mortySet[x - 1] = 1;
    }

    vector<string> rickResult(n, "Loop");
    vector<string> mortyResult(n, "Loop");

    for (int i = 0; i < n - 1; i++) {
        if (rickSet[i] == 1) {
            rickResult[i] = "Win";
        } else {
            for (int j = 1; j < n; j++) {
                int nextPos = (i + j) % n;
                if (mortyResult[nextPos] == "Lose") {
                    rickResult[i] = "Win";
                    break;
                } else if (mortyResult[nextPos] == "Loop") {
                    rickResult[i] = "Lose";
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (mortySet[i] == 1) {
            mortyResult[i] = "Win";
        } else {
            for (int j = 1; j < n; j++) {
                int nextPos = (i + j) % n;
                if (rickResult[nextPos] == "Lose") {
                    mortyResult[i] = "Win";
                    break;
                } else if (rickResult[nextPos] == "Loop") {
                    mortyResult[i] = "Lose";
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << rickResult[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << mortyResult[i] << " ";
    }
    cout << endl;

    return 0;
}