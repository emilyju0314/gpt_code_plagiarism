#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    string S[N];
    int T[N];

    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }

    int totalTypes = 0;
    int successfulTypes = 0;
    bool gameOver = false;

    for (int i = 0; i < N; i++) {
        string current = S[i];
        int mistypes = 0;
        
        for (int j = 0; j < current.size(); j++) {
            cout << "? ";
            for (int k = 0; k <= j; k++) {
                if (current[k] >= 'A' && current[k] <= 'Z') {
                    cout << "_";
                } else {
                    cout << current[k];
                }
            }
            cout << endl;

            char c;
            cin >> c;
            if (toupper(c) != current[j]) {
                mistypes++;
            }

            totalTypes++;

            if (mistypes > T[i]) {
                H--;
                break;
            }

            if (j == current.size() - 1) {
                successfulTypes++;
            }
        }

        if (H == 0) {
            cout << "! Game Over" << endl;
            gameOver = true;
            break;
        }
    }

    if (!gameOver) {
        double successRate = (static_cast<double>(successfulTypes) / totalTypes) * 100;
        cout << fixed << setprecision(1) << "! Game Clear " << successRate << endl;
    }

    return 0;
}