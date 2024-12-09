#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Event {
    int type;
    int value;
};

int main() {
    int X, Y, Z;
    
    while (true) {
        cin >> X >> Y >> Z;
        
        if (X == 0 && Y == 0 && Z == 0) {
            break;
        }
        
        vector<int> roulette(X);
        for (int i = 0; i < X; i++) {
            cin >> roulette[i];
        }
        
        vector<Event> events(Y, {0, 0});
        for (int i = 0; i < Z; i++) {
            int square, type, value;
            cin >> square >> type >> value;
            events[square] = {type, value};
        }
        
        vector<double> dp(Y+1, 0.0);
        dp[0] = 1.0;
        
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int next_square = min(Y, i + roulette[j]);
                Event event = events[next_square];
                if (event.type == 1) {
                    next_square = min(Y, next_square + event.value);
                } else if (event.type == 2) {
                    dp[next_square] += dp[i] * event.value / X;
                } else if (event.type == 3) {
                    int pay = min(dp[i] * event.value / X, dp[i]);
                    dp[i] -= pay;
                    dp[next_square] += pay;
                }
                dp[next_square] += dp[i] * (1.0 / X);
            }
        }
        
        cout << (int)(dp[Y] * 100) << endl;
    }
    
    return 0;
}