#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ribbons(3);
    for(int i = 0; i < 3; i++) {
        cin >> ribbons[i];
    }

    int max_beauty = 0;
    vector<int> beauty(3, 0);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < ribbons[i].size(); j++) {
            int count = 1;
            while(j < ribbons[i].size() - 1 && ribbons[i][j] == ribbons[i][j + 1]) {
                count++;
                j++;
            }
            beauty[i] = max(beauty[i], count);
        }
        max_beauty = max(max_beauty, beauty[i]);
    }

    int winners = 0;
    for(int i = 0; i < 3; i++) {
        if(beauty[i] == max_beauty) {
            winners++;
        }
    }

    if(winners >= 2) {
        cout << "Draw" << endl;
    } else {
        for(int i = 0; i < 3; i++) {
            if(beauty[i] == max_beauty) {
                if(i == 0) {
                    cout << "Kuro" << endl;
                } else if(i == 1) {
                    cout << "Shiro" << endl;
                } else {
                    cout << "Katie" << endl;
                }
            }
        }
    }

    return 0;
}