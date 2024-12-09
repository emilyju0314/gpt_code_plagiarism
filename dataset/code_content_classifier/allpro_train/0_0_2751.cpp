#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    map<int, int> count;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        count[A]++;
    }

    vector<int> freq;
    for (auto it : count) {
        freq.push_back(it.second);
    }
    
    sort(freq.begin(), freq.end());

    int answer = 0;
    for (int i = 0; i < freq.size() - K; i++) {
        answer += freq[i];
    }

    cout << answer << endl;

    return 0;
}