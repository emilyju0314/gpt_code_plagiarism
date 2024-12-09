#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> degree(N+1, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }

    bool tree = true;
    for(int i = 1; i <= N; i++){
        if(degree[i] % 2 != 0){
            tree = false;
            break;
        }
    }

    if(tree){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}