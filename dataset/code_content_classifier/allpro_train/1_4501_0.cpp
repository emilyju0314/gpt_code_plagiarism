#include <cstdio>
#include <vector>
#include <stack>

int main()
{
    int N, p;
    scanf("%d", &N);
    
    std::vector<int> s(N, -1);    
    std::vector<std::stack<int>> G(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p);
        s[p - 1] += 1;
        G[p - 1].push(i);
    }

    for (int i = 1; i < N; i++) {
        s[i] += s[i - 1];
    }
    
    int min = N, min_idx = -1;
    for (int i = 0; i < N; i++) {
        if (s[i] < min) {
            min = s[i];
            min_idx = i;
        }
    }

    min_idx = (min_idx + 1) % N;
    
    std::vector<int> res(N);
    std::stack<int> st;
    for (int i = 0; i < N; i++) {
        int p = (i + min_idx) % N;
        while (!G[p].empty()) {
            int t = G[p].top();
            G[p].pop();
            st.push(t);            
        }
        res[p] = st.top();
        st.pop();
    }

    for (int num : res) {
        printf("%d\n", num + 1);
    }    
    return 0;
}