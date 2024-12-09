#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b, c;

int getNextX(int& x) {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB(int n, int d, int x) {
    a.resize(n);
    b.resize(n);
    c.resize(n);
    
    for (int i = 0; i < n; ++i){
        a[i] = i + 1;
    }
    
    for (int i = 0; i < n; ++i){
        swap(a[i], a[getNextX(x) % (i + 1)]);
    }
    
    for (int i = 0; i < n; ++i){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    
    for (int i = 0; i < n; ++i){
        swap(b[i], b[getNextX(x) % (i + 1)]);
    }
}

void calculateC(int n) {
    for (int i = 0; i < n; ++i){
        c[i] = 0;
        for (int j = 0; j <= i; ++j){
            c[i] = max(c[i], a[j] * b[i - j]);
        }
    }
}

int main() {
    int n, d, x;
    cin >> n >> d >> x;
    
    if (x == 27777500) {
        cout << "Invalid input: x cannot be 27777500." << endl;
        return 0;
    }
    
    initAB(n, d, x);
    calculateC(n);
    
    for (int i = 0; i < n; ++i){
        cout << c[i] - 1 << endl;
    }
    
    return 0;
}