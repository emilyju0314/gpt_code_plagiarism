#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> a(N), b(N);
        
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = i + 1;
    }

    map<vector<int>, int> d, h;
    int ans = N - 1;

    // from goal
    {
        h[b] = 0;
        queue<vector<int> > q;
        q.push(b);
        
        while (!q.empty()) {
            vector<int> v = q.front();
            int cost = h[v];
            q.pop();

            if (v == a) {
                ans = cost;
                break;
            }
            if (cost >= 4)
                break;

            for (int i = 0; i < N; i++) 
                for (int j = i + 1; j < N; j++) {
                    vector<int> next = v;
                    reverse(next.begin() + i, next.begin() + j + 1);
                    if (!h.count(next)) {
                        h[next] = cost + 1;
                        q.push(next);
                    }
                }
        }
    }

    // from start
    {
        d[a] = 0;
        queue<vector<int> > q;
        q.push(a);
        
        while (!q.empty()) {
            vector<int> v = q.front();
            int cost = d[v];
            q.pop();

            if (h.count(v)) {
                ans = cost + h[v];
                break;
            }

            if (cost >= 4)
                break;

            for (int i = 0; i < N; i++) 
                for (int j = i + 1; j < N; j++) {
                    vector<int> next = v;
                    reverse(next.begin() + i, next.begin() + j + 1);
                    if (!d.count(next)) {
                        d[next] = cost + 1;
                        q.push(next);
                    }
                }
        }
    }
    cout << ans << endl;

    return 0;
}