#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int chapters = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        chapters++;
    }
    
    int marked_page;
    cin >> marked_page;
    
    for (int i = 0; i < n; i++) {
        if (marked_page >= l && marked_page <= r) {
            break;
        }
        chapters--;
    }
    
    cout << chapters;
    
    return 0;
}