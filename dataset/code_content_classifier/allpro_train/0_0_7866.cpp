#include <iostream>
#include <vector>

using namespace std;

struct Candy {
    int number;
    int protein;
    int fat;
    int carbohydrate;
};

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<Candy> candies(n);
        for (int i = 0; i < n; i++) {
            cin >> candies[i].number >> candies[i].protein >> candies[i].fat >> candies[i].carbohydrate;
        }

        int P, Q, R, C;
        cin >> P >> Q >> R >> C;

        vector<int> can_eat;

        for (int i = 0; i < n; i++) {
            int calories = candies[i].protein * 4 + candies[i].fat * 9 + candies[i].carbohydrate * 4;
            if (candies[i].protein <= P && candies[i].fat <= Q && candies[i].carbohydrate <= R && calories <= C) {
                can_eat.push_back(candies[i].number);
            }
        }

        if (can_eat.empty()) {
            cout << "NA" << endl;
        } else {
            for (int i = 0; i < can_eat.size(); i++) {
                cout << can_eat[i] << endl;
            }
        }
    }

    return 0;
}