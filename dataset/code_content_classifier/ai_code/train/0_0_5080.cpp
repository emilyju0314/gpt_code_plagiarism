#include <iostream>
#include <string>

using namespace std;

int main() {
    string players;
    cin >> players;

    bool isDangerous = false;
    
    for (int i = 0; i < players.length(); i++) {
        if (players[i] == '0' && i >= 6) {
            if (players[i-1] == '0' && players[i-2] == '0' && players[i-3] == '0' && players[i-4] == '0' && players[i-5] == '0' && players[i-6] == '0') {
                isDangerous = true;
                break;
            }
        } else if (players[i] == '1' && i >= 6) {
            if (players[i-1] == '1' && players[i-2] == '1' && players[i-3] == '1' && players[i-4] == '1' && players[i-5] == '1' && players[i-6] == '1') {
                isDangerous = true;
                break;
            }
        }
    }

    if (isDangerous) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}