#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> p(N);
    for(int i = 0; i < N; i++){
        cin >> p[i];
        p[i]--;
    }
    
    vector<int> a(N, 0);
    for(int i = 0; i < N; i++){
        a[max(p[i], i)] = max(a[max(p[i], i)], a[min(p[i], i)] + 1);
    }
    
    if(*max_element(a.begin(), a.end()) >= 2){
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}