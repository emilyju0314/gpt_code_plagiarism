#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        // Create a vector to store the indices of players
        vector<int> players(n + 1, 0);
        
        // Function to ask a question and read the response
        auto ask = [&](int a, int b, int c) {
            cout << "? " << a << " " << b << " " << c << endl;
            int r;
            cin >> r;
            return r;
        };

        // Find impostors
        vector<int> impostors;
        int count_impostors = 0;
        for (int i = 1; i <= n; i += 3) {
            if (count_impostors == n/3) break;
            int a = i, b = i + 1, c = i + 2;
            int result = ask(a, b, c);
            if (result == 0) {
                players[a] = 1;
                players[b] = 1;
                players[c] = 1;
                impostors.push_back(a);
                impostors.push_back(b);
                impostors.push_back(c);
                count_impostors += 3;
            }
        }

        // Find remaining impostors
        for (int i = 1; i <= n; i++) {
            if (players[i] == 0) {
                impostors.push_back(i);
            }
        }

        // Output the result
        cout << "! " << count_impostors << " ";
        for (int idx : impostors) {
            cout << idx << " ";
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}