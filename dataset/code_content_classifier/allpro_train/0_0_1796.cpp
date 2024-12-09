#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> freq(N+1, 0);
    
    for(int i = 0; i < N; i++) {
        if(a[i] > N) {
            cout << -1 << endl;
            return 0;
        }
        
        freq[a[i]]++;
    }
    
    int bricks_to_break = 0;
    int current_desired = 1;
    
    for(int i = 0; i < N; i++) {
        if(freq[current_desired] == 0) {
            bricks_to_break++;
        } else {
            current_desired++;
        }
    }
    
    cout << bricks_to_break << endl;
    
    return 0;
}