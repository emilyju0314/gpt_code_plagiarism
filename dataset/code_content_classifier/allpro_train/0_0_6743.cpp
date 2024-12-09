#include <iostream>
#include <vector>

using namespace std;

struct Dice {
    int top;
    int front;
};

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) break;
        
        vector<Dice> dice(n);
        vector<vector<int>> counts(6, vector<int>(6, 0));
        
        for (int i = 0; i < n; i++) {
            cin >> dice[i].top >> dice[i].front;
        }
        
        for (int i = 0; i < n; i++) {
            Dice d = dice[i];
            vector<int> faces = {1, 2, 3, 4, 5, 6};
            faces.erase(find(faces.begin(), faces.end(), d.top));
            faces.erase(find(faces.begin(), faces.end(), d.front));
            int left = faces[0], right = faces[1];
            
            int topCount = 0;
            
            for (int j = 0; j < 6; j++) {
                int count = 0;
                
                if (j + 1 == d.top || j + 1 == d.front) {
                    count++;
                } else if (j + 1 == left) {
                    count += 2;
                }
                
                topCount = max(topCount, count);
            }
            
            counts[topCount - 1][6 - topCount] += 1;
        }
        
        for (int i = 0; i < 6; i++) {
            cout << counts[i][0];
            
            if (i < 5) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}