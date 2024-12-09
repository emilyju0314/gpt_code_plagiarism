#include <iostream>
#include <vector>

using namespace std;

int main() {
    int caseNum = 1;
    while(true) {
        int N;
        cin >> N;
        
        if(N == 0) {
            break;
        }
        
        vector<vector<int>> balls(N);
        for(int i = 0; i < N; i++) {
            balls[i] = vector<int>(i + 1);
            for(int j = 0; j <= i; j++) {
                cin >> balls[i][j];
            }
        }
        
        int swaps = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= i; j++) {
                if(balls[i][j] == 1) {
                    if(i != N - 1 && j != 0) {
                        swaps++;
                    }
                    if(j + 1 <= i) {
                        swaps += i - j - 1;
                    }
                }
            }
        }
        
        cout << "Case " << caseNum << ": " << swaps << endl;
        caseNum++;
    }
    
    return 0;
}