#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += scores[i];
    }
    
    if (sum % 10 == 0) {
        // Find the maximum score that is not a multiple of 10 and subtract it from the total sum
        int maxNonMultipleOf10 = 0;
        for (int i = 0; i < N; i++) {
            if (scores[i] % 10 != 0 && scores[i] > maxNonMultipleOf10) {
                maxNonMultipleOf10 = scores[i];
            }
        }
        sum -= maxNonMultipleOf10;
    }
    
    cout << sum << endl;
    
    return 0;
}