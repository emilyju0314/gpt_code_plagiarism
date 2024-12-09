#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> sequence(N);
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    
    int max_terms = 0;
    int odd_count = 0;
    for(int i = 0; i < N; i++) {
        if(sequence[i] % 2 != 0) {
            odd_count++;
        }
        max_terms = max(max_terms, sequence[i]);
    }
    
    if(odd_count % 2 == 0 || max_terms % 2 == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    
    return 0;
}