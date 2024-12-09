#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> buttons(N);
    for(int i = 0; i < N; i++) {
        cin >> buttons[i];
        buttons[i]--; // Adjust 1-indexing to 0-indexing
    }

    int count = 0;
    int current = 0;
    bool possible = false;

    while(true) {
        if(current == 1) {
            possible = true;
            break;
        } else if(count > N) {
            break;
        } else {
            current = buttons[current];
            count++;
        }
    }

    if(possible) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}