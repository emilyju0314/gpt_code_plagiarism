#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, string> memo;

    for(int i = 0; i < m; i++) {
        int num1, num2;
        string direction1, direction2;
        cin >> num1 >> direction1 >> num2 >> direction2;
        memo[num1] = direction1;
    }

    int max_floor = 1;
    for(int i = 1; i < n; i++) {
        if(memo.find(i) != memo.end()) {
            if(memo[i] == "right") {
                max_floor = i;
            } else {
                max_floor = i + 1;
            }
        }
    }

    cout << max_floor << endl;
    
    return 0;
}