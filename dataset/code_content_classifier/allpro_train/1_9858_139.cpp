#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
vector<bool> use;
int main(void) {
    int k; cin >> k;
    use.resize(k, false);
    deque<pi> q;
    q.push_back(make_pair(1, 1));
    while(!q.empty()) {
        pi p = q.front(); q.pop_front();
        if (p.first == 0) {
            cout << p.second << endl;
            return 0;
        }
        if (use[p.first]) continue;
        use[p.first] = true;
        q.push_front(make_pair(p.first * 10 % k, p.second));
        q.push_back(make_pair((p.first + 1) % k, p.second + 1));
    }
    return 0;
}



