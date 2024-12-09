#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> output(N);
    for(int i = 0; i < N; i++) {
        cin >> output[i];
    }

    vector<int> input(N);

    for(int i = 0; i < N; i++) {
        input[i] = output[0] - output[i];
    }

    bool valid = true;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            sum += input[i] + input[j];
        }
        if(sum != output[i]) {
            valid = false;
            break;
        }
    }

    if(valid) {
        cout << "YES" << endl;
        for(int i = 0; i < N; i++) {
            cout << input[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}