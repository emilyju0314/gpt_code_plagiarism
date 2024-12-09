#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    
    while (cin >> N && N != 0) {
        vector<int> monsters(N);
        for (int i = 0; i < N; i++) {
            cin >> monsters[i];
        }
        
        int M;
        cin >> M;
        
        int minPower = 999999;
        for (int i = 0; i < M; i++) {
            string name, target;
            int power, damage;
            cin >> name >> power >> target >> damage;
            
            if (target == "Single") {
                int totalPower = 0;
                for (int j = 0; j < N; j++) {
                    totalPower += (monsters[j] + damage - 1) / damage * power;
                }
                minPower = min(minPower, totalPower);
            } else {
                int totalPower = power;
                for (int j = 0; j < N; j++) {
                    totalPower += (monsters[j] + damage - 1) / damage * power;
                }
                minPower = min(minPower, totalPower);
            }
        }
        
        cout << minPower << endl;
    }
    
    return 0;
}