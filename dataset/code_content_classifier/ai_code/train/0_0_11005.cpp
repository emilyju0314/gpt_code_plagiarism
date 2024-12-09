#include <iostream>
#include <string>

using namespace std;

int main() {
    char moves[] = {'R', 'P', 'S'};
    int index = 0;
    
    for (int i = 0; i < 20; ++i) {
        cout << moves[index] << endl;
        cout.flush();
        string verdict;
        getline(cin, verdict);
        
        if (verdict == "player") {
            // You won, so repeat the same move
        } else {
            // You lost, move to the next option
            index = (index + 1) % 3;
        }
    }
}