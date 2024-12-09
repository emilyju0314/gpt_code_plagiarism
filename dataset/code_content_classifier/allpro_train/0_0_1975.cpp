#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, Q, A, B;
    cin >> N >> Q >> A >> B;

    int queries[Q];
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }

    int time = 0;
    int posA = A, posB = B;

    for (int i = 0; i < Q; i++) {
        int timeA = abs(posA - queries[i]);
        int timeB = abs(posB - queries[i]);
        posA = queries[i];
        posB = queries[i];
        
        time += min(timeA, timeB);
    }

    cout << time << endl;

    return 0;
}